#include <stdio.h>
#include <string.h>

int cmsUtl_strcmp(const char* s1, const char* s2)
{
    char emptyStr = '\0';

    if (!s1)
    {
        s1 = &emptyStr;    
    }

    if (!s2)
    {
        s2 = &emptyStr;
    }

    return strcmp(s1, s2);
}

int main()
{
#if 0
    /* Test case 1 */
    char *s1 = NULL;
    char *s2 = NULL;
#endif

#if 0
    /* Test case 2 */
    char *s1 = NULL;
    char *s2 = "China";
#endif

#if 0
    /* Test case 3 */
    char *s1 = "China";
    char *s2 = NULL;
#endif
    char *s1 = "China";
    char *s2 = "china";
    printf ("%d\n", cmsUtl_strcmp(s1, s2));
    return 0;
}
