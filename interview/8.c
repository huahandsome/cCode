#include <stdio.h>

void strReverse(char *str);
int main()
{
    char buf[] = "abcdef";
    strReverse(buf);
    
    printf("%s\n", buf);
    return 0;
}

void strReverse(char *str)
{
    if (!str)
        printf("...\n");

    char *head = str;
    char *tail = str;

    while(*tail != '\0')
        tail++;
    tail--;
    char c;
    while(head < tail)
    {
        c = *head;
        *head = *tail;
        *tail = c;

        head++;
        tail--;
    }
}

