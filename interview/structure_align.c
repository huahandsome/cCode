#include <stdio.h>
#define OFFSETOF(Type, Member)   ((unsigned int) (&(((Type*)0)->Member)))
// Alignment requirements
// (typical 32 bit machine)
// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes

// structure A
typedef struct structa_tag
{
    char        c;
    short int   s;
} structa_t;

// structure B
typedef struct structb_tag
{
    short int   s;
    char        c;
    int         i;
} structb_t;

// structure C
typedef struct structc_tag
{
     char        c;
     double      d;
     int         s;
} structc_t;
                              
// structure D
typedef struct structd_tag
{
    double      d;
    int         s;
    char        c;
} structd_t;

int main()
{
    printf("sizeof(structa_t) = %d\n", (int)sizeof(structa_t));
//    printf("%x \n", OFFSETOF(struct structa_tag, c)/*, OFFSETOF(struct structa_tag, s)*/);
    printf("%ld %ld\n", sizeof(int *), sizeof(int) );

    printf("sizeof(structb_t) = %d\n", (int)sizeof(structb_t));
//  printf("%d %d\n", OFFSETOF(structb_t, s), OFFSETOF(structb_t, c), OFFSETOF(structb_t, i));

    printf("sizeof(structc_t) = %d\n", (int)sizeof(structc_t));
//  printf("%d %d\n", OFFSETOF(structc_t, c), OFFSETOF(structc_t, d), OFFSETOF(structc_t, s));

    printf("sizeof(structd_t) = %d\n", (int)sizeof(structd_t));
//  printf("%d %d\n", OFFSETOF(structc_t, c), OFFSETOF(structc_t, d), OFFSETOF(structc_t, s));
                            
    return 0;
}
