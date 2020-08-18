#include <string.h>

char *strnstr(const char *big, const char *little, size_t len);

 
/*
이 함수는 big 문자열에 len 길이 중에서 little 문자열을 찾는 것이다.

 

반환 값

만약 little 값이 비어 있으면 big를 반환한다.

big 문자열에서 little 문자열을 찾지 못하면 NULL을 반환한다.

little 문자열을 찾으면 big에 little 문자열 시작 부분 위치 주소를 반환한다.
*/