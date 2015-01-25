#include <stdio.h>
#include <string.h>

int main()
{
//    char *str = "Nation=China&City=Nanjing&Company=Calix\n";
    char str[] = "Nation=China&City=Nanjing&Company=Calix\n";
    char *p = str;
    char *p1 = NULL;

    p1 = strsep(&p, "&");
    printf("%s, %s\n", p1, p);
    return 0;
}
