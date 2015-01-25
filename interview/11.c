#include <stdio.h>
#include <string.h>

char *_strdup(const char *src)
{
    static char buf [100];
    strcpy(buf, src);
    
    return buf;
}

int main()
{
    char *str = "abcdef";
    printf("%s\n", _strdup(str));
    return 0;
}
