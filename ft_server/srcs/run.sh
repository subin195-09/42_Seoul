 #!/bin/bash

#/bin/bash -C

service mysql start
service php7.3-fpm start
nginx -g  "daemon off;"
