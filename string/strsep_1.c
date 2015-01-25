#include <stdio.h>
#include <string.h>

int main()
{
//    char *str = "Nation=China&City=Nanjing&Company=Calix\n";
    char str[] = "Nation=China&City=Nanjing&Company=Calix\n";
    char *next = str;
    char *p1 = NULL;
    char *p2 = NULL;

    while (next)
    {
        p1 = strsep(&next, "&");
        p2 = strsep(&p1, "=");
        printf("%s is %s\n", p2, p1);
    }
//    printf("%s, %s\n", p1, p);
    return 0;
}
