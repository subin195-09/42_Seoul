SRC_DIR = ./srcs
COMPOSE = docker-compose
YML = docker-compose.yml
RUN_COM = $(COMPOSE) -f $(SRC_DIR)/$(YML)

up:
	$(RUN_COM) up

up_d:
	$(RUN_COM) up -d

build:
	$(RUN_COM) build

restart:
	$(RUN_COM) restart

ls:
	$(RUN_COM) ps

port:
	$(RUN_COM) port

down:
	$(RUN_COM) down

down_rmi:
	$(RUN_COM) down --rmi all
