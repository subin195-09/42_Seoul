FROM	debian:buster


LABEL	maintainer="skim@student.42seoul.kr"

RUN		apt-get update -y; \
		apt-get	upgrade -y; \
		apt-get install -y php-fpm wget

RUN		wget https://wordpress.org/latest.tar.gz;

RUN		tar -xvf latest.tar.gz;

RUN		service php7.3-fpm start
			
EXPOSE	9000

CMD sleep infinity 