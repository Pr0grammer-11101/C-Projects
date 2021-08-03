#include<stdio.h>
#include<stdlib.h>


// my version of strcmp()

int string_cmp(char *, char *);

int main(void)
{
	char *s1, *s2;

	int size1, size2;

	printf("Enter the length of the first string....");
	scanf("%d", &size1);
	printf("Enter the length of the second string....");
	scanf("%d", &size2);

	s1=(char *)malloc(size1*sizeof(char));

	s2=(char *)malloc(size2*sizeof(char));

	int i=0;

	printf("enter the two strings....\n\n");

	printf("\nString 1-> ");
	while(i<size1)
	{
		scanf(" %c", s1+i);

		i++;
	}

	printf("\nString 2-> ");
	i=0;
	while(i<size2)
	{
		scanf(" %c", s2+i);
		i++;
	}

	int result;

	result=string_cmp(s1, s2);

	if(result==0)
	{
		printf("\nThe strings are equal...\n\n");

	}

	else
	{
		printf("\nThe strings are not equal...\n\n");
	}

	free(s1), free(s2);

	return 0;
}

int string_cmp(char *s1, char *s2)
{

	while(*s1!='\0' || *s2!='\0')
	{
		if(*s1!=*s2)
			return -1;

		s1++, s2++;
	}


	return 0;
}
