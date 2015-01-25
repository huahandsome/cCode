#include <stdio.h>
#include <string.h>

char *cmsUtl_strcpy(char *dst, const char *src)
{
    if (!dst)
    {
        printf("dst is NULL\n");
        return dst;
    }

    if (!src)
        return strcpy(dst, "");
    else
        return strcpy(dst, src);
}


int main()
{
    char dst[100];
    char *src = NULL;
    char *p = NULL;
    p = cmsUtl_strcpy(dst, src);

    if (p)
        printf("%s\n", p);
    return 0;
}

