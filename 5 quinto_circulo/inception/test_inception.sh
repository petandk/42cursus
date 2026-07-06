#!/bin/bash

# ==============================================================================
# DEFINITIVE INCEPTION AUDIT SCRIPT - 42 CURRICULUM (v2.2)
# ==============================================================================

# If no argument is passed, use the current operating system user
LOGIN=${1:-$USER}
DOMAIN="$LOGIN.42.fr"
HOME_DATA_PATH="/home/$LOGIN/data"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
NC='\033[0m'

echo -e "${CYAN}=================================================================${NC}"
echo -e "${CYAN}       INCEPTION AUDIT FOR LOGIN: ${YELLOW}$LOGIN${NC}"
echo -e "${CYAN}=================================================================${NC}"

# 1. MANDATORY STRUCTURE AND FILES
echo -e "\n${YELLOW}[1/8] Checking basic structure and mandatory files...${NC}"
FILES=("Makefile" "README.md" "USER_DOC.md" "DEV_DOC.md" "srcs/docker-compose.yml")
for file in "${FILES[@]}"; do
    if [ -f "$file" ]; then
        echo -e "  [OK] $file exists."
    else
        echo -e "  ${RED}[FATAL] $file DOES NOT exist or is not in the root/correct path.${NC}"
    fi
done

# Check mandatory first line in README
FIRST_LINE=$(head -n 1 README.md 2>/dev/null)
if [[ "$FIRST_LINE" == *"This project has been created as part of the 42 curriculum by"* ]]; then
    echo -e "  [OK] First line of README.md follows the required format."
else
    echo -e "  ${RED}[FATAL] First line of README.md does not follow the strict italicized format.${NC}"
fi

# 2. GIT SECRET TRACKING CHECK (.env and secrets)
echo -e "\n${YELLOW}[2/8] Checking Git repository security (.env and secrets)...${NC}"
ENV_TRACKED=$(git ls-files 2>/dev/null | grep -iE "\.env$|secret")
if [ -z "$ENV_TRACKED" ]; then
    echo -e "  [OK] No .env or secret files tracked in the Git repository."
else
    echo -e "  ${RED}[FATAL] SENSITIVE FILES IN GIT! Direct 0 risk: $ENV_TRACKED${NC}"
fi

# 3. FORBIDDEN COMMANDS AND BAD PRACTICES IN CODE
echo -e "\n${YELLOW}[3/8] Scanning Dockerfiles, Makefile, and Scripts in srcs/...${NC}"
FORBIDDEN=("tail -f" "sleep infinity" "while true" "network: host" "links:" "--link" ":latest")
FOUND_ERR=0
for term in "${FORBIDDEN[@]}"; do
    MATCH=$(grep -rn "$term" srcs/ Makefile 2>/dev/null)
    if [ ! -z "$MATCH" ]; then
        echo -e "  ${RED}[FATAL] Forbidden term '$term' found in:${NC}\n$MATCH"
        FOUND_ERR=1
    fi
done
if [ $FOUND_ERR -eq 0 ]; then
    echo -e "  [OK] Zero artificial infinite loops, host networks, or 'latest' tags found."
fi

# 4. DOCKER NETWORK AUDIT (ISOLATION AND INTERNAL DNS)
echo -e "\n${YELLOW}[4/8] Auditing custom network and connectivity...${NC}"
CUSTOM_NET=$(docker network ls --format "{{.Name}}" | grep -vE "^(bridge|host|none)$" | head -n 1)
if [ ! -z "$CUSTOM_NET" ]; then
    echo -e "  [OK] Custom network detected: ${CYAN}$CUSTOM_NET${NC}"
    
    # Check which containers are connected to that LAN network
    NET_CONTAINERS=$(docker network inspect "$CUSTOM_NET" --format '{{range .Containers}}{{.Name}} {{end}}' 2>/dev/null)
    echo -e "  [OK] Containers connected to the LAN network: ${CYAN}$NET_CONTAINERS${NC}"
else
    echo -e "  ${RED}[FATAL] No active custom Docker network detected.${NC}"
fi

# 5. CONTAINERS EXECUTION STATE (PID 1 Foreground)
echo -e "\n${YELLOW}[5/8] Checking containers execution state (PID 1 Foreground)...${NC}"
CONTAINERS=("nginx" "wordpress" "mariadb")
for c in "${CONTAINERS[@]}"; do
    STATUS=$(docker ps --filter "name=$c" --format "{{.Status}}" | grep -i "up")
    if [ ! -z "$STATUS" ]; then
        echo -e "  [OK] Container '$c' is active and running ($STATUS)."
    else
        echo -e "  ${RED}[FATAL] Container '$c' is NOT running.${NC}"
    fi
done

# 6. PERSISTENT VOLUMES INSPECTION (Local Bind in $HOME_DATA_PATH)
echo -e "\n${YELLOW}[6/8] Auditing persistent volumes (Local Bind in $HOME_DATA_PATH)...${NC}"
VOLS=$(docker volume ls -q)
if [ -z "$VOLS" ]; then
    echo -e "  ${RED}[FATAL] No Docker volumes created.${NC}"
else
    for v in $VOLS; do
        # Check both 'device' (bind opts) and 'Mountpoint' for the user path
        VALID_PATH=$(docker volume inspect "$v" | grep -E "($LOGIN/data|$USER/data)")
        if [ ! -z "$VALID_PATH" ]; then
            echo -e "  [OK] Volume '$v' correctly bound to physical host path in /data/."
        else
            echo -e "  ${RED}[FATAL] Volume '$v' does not contain /home/$LOGIN/data in its configuration.${NC}"
        fi
    done
fi

# 7. NETWORK SSL/TLS AND PORT TESTING
echo -e "\n${YELLOW}[7/8] Testing web access and SSL/TLS on $DOMAIN...${NC}"
if grep -q "$DOMAIN" /etc/hosts 2>/dev/null; then
    echo -e "  [OK] $DOMAIN is correctly mapped in /etc/hosts."
else
    echo -e "  ${RED}[WARNING] $DOMAIN is NOT in /etc/hosts. Browser access will fail.${NC}"
fi

# Check that port 80 (HTTP) rejects the connection
HTTP_CODE=$(curl -o /dev/null -s -w "%{http_code}" --connect-timeout 2 "http://$DOMAIN" 2>/dev/null)
if [ "$HTTP_CODE" == "000" ] || [ -z "$HTTP_CODE" ]; then
    echo -e "  [OK] Port 80 (HTTP) closed/rejected as required by the project."
else
    echo -e "  ${RED}[FATAL] Port 80 answered with HTTP $HTTP_CODE. Must only serve on port 443!${NC}"
fi

# Check HTTPS connection with TLSv1.2 or v1.3
TLS_CHECK=$(curl -k -I -s --tlsv1.2 "https://$DOMAIN" 2>/dev/null | head -n 1)
if [[ "$TLS_CHECK" == *"200"* ]] || [[ "$TLS_CHECK" == *"302"* ]] || [[ "$TLS_CHECK" == *"301"* ]]; then
    echo -e "  [OK] HTTPS connection via TLSv1.2+ operational ($TLS_CHECK)."
else
    echo -e "  ${RED}[FATAL] HTTPS access to domain failed. Response: $TLS_CHECK${NC}"
fi

# 8. ANTI-CHEAT AUDIT: WORDPRESS AND DB USERS
echo -e "\n${YELLOW}[8/8] Verifying username rules (no 'admin' allowed)...${NC}"
# Only check what is ON THE RIGHT side of '=' (the actual username value)
ADMIN_USER_CHECK=$(grep -iE "^(WP_ADMIN_LOGIN|WP_USER|MYSQL_USER|MYSQL_DATABASE)=" srcs/.env 2>/dev/null | cut -d '=' -f2 | grep -i "admin")
if [ -z "$ADMIN_USER_CHECK" ]; then
    echo -e "  [OK] No username value in your .env contains the forbidden word 'admin'."
else
    echo -e "  ${RED}[FATAL] ALERT! One of your username values is invalid and contains 'admin':${NC}\n$ADMIN_USER_CHECK"
fi

echo -e "\n${CYAN}=================================================================${NC}"
echo -e "${GREEN} AUTOMATED AUDIT COMPLETED.${NC}"
echo -e " Remember to perform the manual fire test during your defense:"
echo -e "   1. Edit a page or post at https://$DOMAIN/wp-admin"
echo -e "   2. Run ${YELLOW}sudo reboot${NC}"
echo -e "   3. Verify that changes persist after system restart."
echo -e "${CYAN}=================================================================${NC}"