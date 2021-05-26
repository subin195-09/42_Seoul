FROM	debian:buster

ARG		WP_NAME=wordpress
ARG		WP_USER=skim
ARG		WP_PWD=1234

LABEL	maintainer="skim@student.42seoul.kr"

RUN		apt-get update -y; \
		apt-get	upgrade -y; \
		apt-get install -y mariadb-server

RUN		service mysql start; \
		mysql -e  "CREATE DATABASE ${WP_NAME}; \
		USE ${WP_NAME}; \
		CREATE USER '${WP_USER}'@'localhost' IDENTIFIED BY '${WP_PWD}'; \
		GRANT ALL PRIVILEGES ON ${WP_NAME}.* TO '${WP_USER}'@'localhost' WITH GRANT OPTION; \
		FLUSH PRIVILEGES;"

EXPOSE	3306
