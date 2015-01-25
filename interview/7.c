#include <stdio.h>
#include <string.h>

void Reverse(char **str);
int main()
{
    char buf[] = "abcdefghij";
    char *tmp = buf;
    Reverse(&tmp);
    printf("%s\n", buf);
    return 0;
}

void Reverse(char **str)
{
    char *tmp = *str;
    if (!tmp)
        printf("error\n");

    printf("orig string: %s\n", tmp);

    int len = strlen(tmp);
    int tail = len-1;
    char c;
    int head = 0;
    int idx = 0;
    len  /= 2;
    for (idx = 0; idx < len; idx++, tail--, head++)
    {
        c = tmp[head];
        tmp[head] = tmp[tail];
        tmp[tail] = c;
    }
}
