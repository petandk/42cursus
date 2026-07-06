# Colors
CYAN    = \033[1;36m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
GREEN	= \033[1;32m
RED     = \033[1;31m
RESET   = \033[0m

all: prepare
	@echo "$(CYAN)🚀 Starting Inception stack...$(RESET)"
	@docker compose -f srcs/docker-compose.yml up --build -d
	@echo "$(CYAN)✅ Stack is up and running!$(RESET)"

attached: prepare
	@echo "$(CYAN)🚀 Starting Inception stack attached mode$(RESET)"
	@docker compose -f srcs/docker-compose.yml up --build
	@echo "$(CYAN)✅ Stack is up and running!$(RESET)"

prepare:
	@if [ ! -f srcs/.env ]; then echo "$(RED)⚠️  .env not found. Create srcs/.env and try again.$(RESET)"; exit 1; fi
	@mkdir -p ${HOME}/data/mariadb
	@mkdir -p ${HOME}/data/wordpress
	@bash ./srcs/requirements/tools/generate_secrets.sh
	
down:
	@echo "$(YELLOW)🛑 Stopping containers...$(RESET)"
	@docker compose -f srcs/docker-compose.yml down
	@echo "$(YELLOW)🛑 Stack stopped.$(RESET)"

clean: down
	@echo "$(YELLOW)🧹 Cleaning unused images...$(RESET)"
	@docker system prune -af
	@echo "$(YELLOW)✨ Clean complete.$(RESET)"

# list volumes and then xargs grabs the output and runs the rm ONLY if the list is not empty (-r)
# docker volumes are stored @ /var/lib/docker/volumes (requires sudo)
fclean: clean
	@echo "$(BLUE)🗑️  Removing data and volumes...$(RESET)"
	@docker volume ls -q | xargs -r docker volume rm
	@docker system prune -af --volumes
	@sudo rm -rf ${HOME}/data
	@ rm -rf ./secrets
	@echo "$(GREEN)💥 Total wipeout!$(RESET)"

ls-vols:
	@docker volume ls

ls-cnt:
	@docker ps -a

logs_%:
	@docker logs $*

shell_%:
	@docker exec -it $* bash

ip:
	@echo "$(GREEN)📟 Available host ips$(RESET)"
	@ip -4 -o addr show | sed -En 's/^[0-9]+: ([^:]+).*inet ([0-9.]+)\/.*/\1:\2/p' | grep -Ev '^(lo|docker0|br-|veth)'

re: fclean all

.PHONY: prepare all down clean fclean ls-vols ls-cnt re attached ip logs_% shell_%



