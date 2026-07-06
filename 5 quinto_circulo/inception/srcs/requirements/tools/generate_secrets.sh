#!/bin/bash

# This script generates secret files in the repository's `secrets` directory.
# It is intended to be run via the Makefile.

# Fixed path for secrets when run from the project root
mkdir -p "./secrets"

# ANSI color codes
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
CYAN="\e[36m"
RESET="\e[0m"

# generate_secret <filename>
# Creates the file with a secure random hex value if it does not already exist.
generate_secret() {
    local file="./secrets/$1"

    if [ ! -f "$file" ]; then
        # Create a secure random hex string
        openssl rand -hex 16 > "$file"
        chmod 600 "$file"
        echo -e "${GREEN}✅ Generated: $1${RESET}"
    else
        echo -e "${YELLOW}ℹ️  Exists: $1 (skipping)${RESET}"
    fi
}

# Info header
echo -e "${CYAN}🔐 Checking and generating secrets in ./secrets${RESET}"

# Generate the password files
generate_secret "db_pass.secret"
generate_secret "db_root_pass.secret"
generate_secret "wp_admin_pass.secret"
generate_secret "wp_user_pass.secret"

echo -e "${BLUE}🚀 All secrets are ready in ./secrets${RESET}"