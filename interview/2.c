#include <stdio.h>

int pheponatch(int n) ;
int main()
{
    int idx = 1;
    while (idx < 10)
    {
        printf("%dth: %d  ", idx, pheponatch(idx));
        idx++;
    }

    printf("\n");
    return 0;
}

int pheponatch(int n)
{
    int ret = 0;
    int a1 = 1, a2 = 1; 
    int a3 = 0;

    if (n == 1 || n == 2)
    {
        ret = a1;
    }
    else // n >= 3
    {
        while (n >= 3)
        {
            n--;
            a3 = a1 + a2;
            a1 = a2;
            a2 = a3;
        }
        ret = a3;
    }
     
    return ret;
}
