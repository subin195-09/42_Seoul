FROM	debian:buster

LABEL	maintainer="skim@student.42seoul.kr"

RUN		apt-get update -y; \
		apt-get	upgrade -y; \
		apt-get install -y php-fpm

COPY	tools	/

RUN		mkdir -p /var/www/html
RUN		tar -xvf wordpress-5.7.2.tar.gz -C /var/www/html;

# RUN		mv /wordpress/wp-config-sample.php /wordpress/wp-config.php; \
# 		sed -i "s/database_name_here/wordpress/g" /wordpress/wp-config.php; \
# 		sed -i "s/username_here/skim/g" /wordpress/wp-config.php; \
# 		sed -i "s/password_here/skim1234/g" /wordpress/wp-config.php

# RUN		mv wordpress/* var/local/;

EXPOSE		9000

CMD 	["sleep", "infinity"]
