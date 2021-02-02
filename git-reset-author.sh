
#!/bin/sh

# Credits: http://stackoverflow.com/a/750191

git filter-branch -f --env-filter "
    GIT_AUTHOR_NAME='subin195-09'
    GIT_AUTHOR_EMAIL='k_subin@naver.com'
    GIT_COMMITTER_NAME='subin195-09'
    GIT_COMMITTER_EMAIL='k_subin@naver.com'
  " HEAD
