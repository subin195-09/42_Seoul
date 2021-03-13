FROM	debian:buster

ARG		WP_NAME=wordpress
ARG		WP_USER=skim
ARG		WP_PWD=1234

# image를 생성한 사람 등을 나타냄
LABEL	maintainer="skim@student.42seoul.kr"

RUN			apt-get update -y; \
			apt-get	upgrade -y
RUN			apt-get install -y nginx openssl php-fpm mariadb-server php-mysql vim wget

COPY		./srcs/* ./

# nginx 설정파일 옮기기
RUN			cp /default	etc/nginx/sites-available/default;

# openssl
RUN			openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
			-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=skim/CN=localhost" \
			-keyout localhost.dev.key -out localhost.dev.crt; \
			mv localhost.dev.crt etc/ssl/certs/; \
			mv localhost.dev.key etc/ssl/private/; \
			chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# mySQL
RUN			service mysql start; \
			mysql -e  "CREATE DATABASE ${WP_NAME}; \
			USE ${WP_NAME}; \
			CREATE USER '${WP_USER}'@'localhost' IDENTIFIED BY '${WP_PWD}'; \
			GRANT ALL PRIVILEGES ON ${WP_NAME}.* TO '${WP_USER}'@'localhost' WITH GRANT OPTION; \
			FLUSH PRIVILEGES;"

# phpmyadmin
RUN			wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz; \
			tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz; \
			mv phpMyAdmin-5.0.2-all-languages phpmyadmin; \
			mv phpmyadmin /var/www/html/ ;\
			cp -rp var/www/html/phpmyadmin/config.sample.inc.php var/www/html/phpmyadmin/config.inc.php

# wordpress
RUN			wget https://wordpress.org/latest.tar.gz; \
			tar -xvf latest.tar.gz; \
			mv wordpress/ var/www/html/; \
			chown -R www-data:www-data /var/www/html/wordpress; \
			cp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php; \
			sed -i "s/database_name_here/${WP_NAME}/g" /var/www/html/wordpress/wp-config.php; \
			sed -i "s/username_here/${WP_USER}/g" /var/www/html/wordpress/wp-config.php; \
			sed -i "s/password_here/${WP_PWD}/g" /var/www/html/wordpress/wp-config.php

# 컨테이너가 해당 포트를 사용할 예정임을 알려줌
# run -p 옵션 뒤에 이 포트번호가 적힘
EXPOSE		80 443

ENTRYPOINT	[ "/bin/bash", "-C", "/run.sh"]
