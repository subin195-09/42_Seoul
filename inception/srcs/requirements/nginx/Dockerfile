FROM	debian:buster

LABEL	maintainer="skim@student.42seoul.kr"

RUN		apt-get update -y; apt-get upgrade -y; \
		apt-get install -y nginx openssl vim

COPY	./conf/default /
RUN		cp /default	etc/nginx/sites-available/default;

RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
		-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=skim/CN=localhost" \
		-keyout localhost.dev.key -out localhost.dev.crt; \
		mv localhost.dev.crt etc/ssl/certs/; \
		mv localhost.dev.key etc/ssl/private/; \
		chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

EXPOSE	443

CMD 	["nginx", "-g", "daemon off;"]
