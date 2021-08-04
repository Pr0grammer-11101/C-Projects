#include<stdio.h>
#include<stdlib.h>

void str_cpy(char *, char *);

int main(void)
{
	char *s1, *s2;
	int size1, size2;

	printf("enter the length of the first string...");
	scanf("%d", &size1);

	printf("enter the length of the second string...");
	scanf("%d", &size2);

	s1=(char *)malloc(size1);
	s2=(char *)malloc(size2);

	printf("enter the two strings...\n\n");

	printf("\nString 1-> ");
	scanf("%s", s1);

	printf("\nString 2-> ");
	scanf("%s", s2);


	printf("\nCopying string 2 to string 1.....\n\n");
	str_cpy(s1, s2);

	free(s1), free(s2);

	return 0;
}

void str_cpy(char *s1, char *s2)
{
	char *p1, *p2;
	p1=s1, p2=s2;

	while(*s1!='\0' && *s2!='\0')
	{
		*s1=*s2;
		s1++, s2++;
	}
	
	s1=p1, s2=p2;

	printf("\nThe strings after copying are...\n\n");

	puts(s1);
	puts(s2);
}
