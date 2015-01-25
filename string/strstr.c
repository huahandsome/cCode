#include <stdio.h>
#include <string.h>

char *cmsUtl_strstr(const char* s1, const char *s2)
{
    char emptyStr = '\0';
    if (!s1)
        s1 = &emptyStr;
    if (!s2)
        s2 = &emptyStr;

    return strstr(s1, s2);
}

int main()
{
    char *p = NULL;
    p = cmsUtl_strstr(s1, s2);
    if (p)
        printf("%s\n", p);
    return 0;
}
