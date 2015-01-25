#include <stdio.h>

void delChar(char*);

int main()
{
//    char buf[] = "acba";
//    char buf[] = "acbac";
//    char buf[] = "aaac";
//    char buf[] = "ababac";
//    char buf[] = "bbbbbbbd";
    char buf[] = "d";
    delChar(buf);
    printf("%s\n", buf);
    return 0;
}
// delete 'b' or "ac" in a string, only traverse one time string 
void delChar(char *str)
{
    char *cur = str;
    char *next = NULL;
    char *tmp = NULL;
    int loopTime = 0;

    if (!cur)
    {
        printf("......\n");
        return;
    }

    while(*cur != '\0')
    {
        if (*cur == 'b')
        {
            loopTime = 1;    // overwrite once
        }
        else if ( *cur == 'a' && *(cur + 1) == 'c')
        {
            loopTime = 2;    // overwirte twice    
        }
        else
        {
            cur++;
            continue;
        }
        int idx ;
        for (idx = 0; idx < loopTime; idx ++)
        {
            tmp = cur;
            next = cur + 1;
            while (*tmp != '\0')
            {
                *tmp = *next;
                tmp++;
                next++;
            }
        }

        loopTime = 0;
    }
}
