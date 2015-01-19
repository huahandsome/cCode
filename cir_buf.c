#include <stdio.h>
#include <string.h>

#define BUF_SIZE 10
char buf[BUF_SIZE +1] = {0};

char *pIn  = buf;
char *pOut = buf;
char *pEnd = &buf[BUF_SIZE];

void buf_put (char ch)
{
    /* circular buf */
    if (pIn == pEnd)
        pIn = buf;

    *pIn = ch;
    pIn++;	
}

int main()
{
    int idx = 0;
    char string[] = "abcdefghijklmn";

    for(; idx < strlen(string); idx++)
        buf_put(string[idx]);
    
    printf("%s\n", buf);
    return 0;
}
