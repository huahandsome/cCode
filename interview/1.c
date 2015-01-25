#include <stdio.h>
#define N 8

int main()
{
    int i ;
    for (i = 0; i < N; i++)
    {
        int j ;
        for (j = 0; j < i + 1; j++)
        {
            printf("*");
            int k = 0;
            for (; k < i; k++)
                printf(".");
        }
        printf("\n");
    }
    return 0;
}
