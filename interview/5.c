#include <stdio.h>

void int2str(int num, char *str);
int main()
{
    char buf[100];
    int2str(-1234567890, buf);
    printf("%s\n", buf);
    return 0;
}

void int2str(int num, char *str)
{
    if (!str)
    {
        printf("str is NULL\n");
        return;
    }
    char *tmp = str;

    if (num < 0)
    {
        num = -num;
        *str = '-';
        str++;
    }

    while(num)
    {
        *str++ = num%10 + '0';
        num = num/10;
    }

    *str = '\0';
    str = tmp;
    printf("%s\n", str); 
    /* re-order */
    int len = 0;
    while(*str++ != '\0')
    {
        len++;
    }

    str = tmp;

    int idx = 0;
    int tail = len;
    char c ;

    if (*str == '-')
    {
        idx = 1;
        len --;
    }
    tail --;

    while(len)
    {
        
        c = str[idx];
        str[idx] = str[tail];
        str[tail] = c;
        idx ++;
        tail --;
        len /= 2;
    }

}
