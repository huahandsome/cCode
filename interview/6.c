#include<stdio.h>
#define TRUE 1
#define FALSE 0

int str2int(const char *str);
int main()
{
    printf("%d\n", str2int("-123abdf45"));
    return 0;
}

int str2int(const char *str)
{
    int ret = 0;
    unsigned char isMinor = FALSE;

    if (*str == '-')
    {
        isMinor = TRUE;
        str++;   
    }
    ret = *str - '0';
    str++;

    while ( *str >= '0' && *str <= '9' )
    {
        ret = ret*10 + *str - '0';
        str++;
    }
    
    if (isMinor)
        ret = -ret;

    return ret;
    
}
