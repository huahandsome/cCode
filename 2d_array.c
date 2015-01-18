#include<stdio.h>

int main()
{
	char string[][40] = {
		"Please give me a help\n",
		"I am finding a job\n",
		"I would like to move out China\n"
	};
	
	// print out sentence
	// 1st way
	int i = 0;
	for(; i< 3; i++)	
	    printf("%dth sentence %s\n", i, *(string+i));

	// 2nd way, using pointer
	char *p[3];
	for(i = 0; i < 3; i++)
	{
            p[i] = string[i];// or p[i] = *(string + i)
	    printf("%dth sentenc %s\n", i, *(p+i));
        }

	// 3rd way	
	char **p1;
	p1 = p;
	for(i = 0; i < 3; i++)
	{
            p[i]= string[i];// or p[i] = *(string + i)
        }
	for(i = 0; i < 3; i++)
	{
            printf("%dth sentence %s\n", i, *(p1 + i));
        }
	
        // 4th way, pointer
	char (*q)[40] = string;
	for(i = 0; i < 3; i++)
	{
	    printf("%dth sentenc %s\n", i, *(q+i));
        }
	
        // print out char
        // 1st way
        printf("%c\n", string[1][3]);
	printf("%c\n", *(*(string + 1)+3));
	// 2nd way: pointer to char
	char *ch;
	ch = &string[1][0];
	printf("%c\n", *(ch + 3));
        // 3rd way	
	char *p2[10];
	p2[0] = *(string + 1);//or p[0] = string[1]
	printf("%c\n", *(p2[0]+3));
        // 4th way
	char (*p3)[40] ;
	p3 = string;
	
	p3 = p3+1;
	printf("%c\n", *(*p3+3));
	
	char **q1;
	q1 = p2;
	printf("%c\n", *(*q1+3));

	
	return 0;
}
