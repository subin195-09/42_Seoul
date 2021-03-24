 #!/bin/bash

service mysql start
service php7.3-fpm start
nginx -g  "daemon off;"
