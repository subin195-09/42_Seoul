FROM	debian:buster

LABEL	maintainer="skim@student.42seoul.kr"

RUN			apt-get update -y; \
			apt-get	upgrade -y; \
			apt-get install -y php-fpm wget

RUN			wget https://wordpress.org/latest.tar.gz; \
			tar -xvf latest.tar.gz; \
			mv wordpress/ var/www/html/; \
			chown -R www-data:www-data /var/www/html/wordpress; \
			cp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php; \
			sed -i "s/database_name_here/${WP_NAME}/g" /var/www/html/wordpress/wp-config.php; \
			sed -i "s/username_here/${WP_USER}/g" /var/www/html/wordpress/wp-config.php; \
			sed -i "s/password_here/${WP_PWD}/g" /var/www/html/wordpress/wp-config.php

EXPOSE		9000
