FROM	debian:buster

# image를 생성한 사람 등을 나타냄
LABEL	maintainer="skim@student.42seoul.kr"

RUN			apt-get update -y; \
			apt-get	upgrade -y
RUN			apt-get install -y nginx openssl vim curl

COPY		./srcs/* ./

RUN			openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
			-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=skim/CN=localhost" \
			-keyout localhost.dev.key -out localhost.dev.crt; \
			mv localhost.dev.crt etc/ssl/certs/; \
			mv localhost.dev.key etc/ssl/private/; \
			chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key; \
			cp /default	etc/nginx/sites-available/default

# 컨테이너가 해당 포트를 사용할 예정임을 알려줌
# run -p 옵션 뒤에 이 포트번호가 적힘
EXPOSE		80 443

ENTRYPOINT	[ "/bin/bash", "-C", "/run.sh"]
