#include <stdio.h>
#include <string.h>

#define BUF_SIZE 10
char buf[BUF_SIZE +1] = {0};

char *pIn  = buf;
char *pEnd = &buf[BUF_SIZE];

void buf_put (char *str)
{
    /* 1st. cal left size */
    int left = BUF_SIZE - (int)(pIn - buf);
    /* 2nd cal string length */
    int len = strlen(str);

    int idx = 0;
    /* circular buf */
    if (len <= left)
    {
        idx = 0;
        for (; idx < len; idx++)
            *pIn++ = *(str+idx) ;
    }
    else
    {
        idx = 0;
        for (; idx < left; idx++)
            *(pIn+idx) = *(str+idx);

        pIn = buf;// move to head
        for (; idx < len; idx ++)
            *pIn++ = *(str+idx);
    }
        
}

int main()
{
    char string[] = "abcdefghijklmn";
//    char string[] = "abcdefghij";
//    char string[] = "abcdefgh";

    buf_put(string);
    printf("%s\n", buf);

    char string1[] = "ABCDEFGHIJKL";
    buf_put(string1);
    
    printf("%s\n", buf);
    return 0;
}
