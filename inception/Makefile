SRC_DIR = ./srcs
COMPOSE = docker-compose
YML = docker-compose.yml
RUN_COM = $(COMPOSE) -f $(SRC_DIR)/$(YML)

up:
	$(RUN_COM) up -d

restart:
	$(RUN_COM) restart

ls:
	$(RUN_COM) ps

port:
	$(RUN_COM) port

down:
	$(RUN_COM) down
