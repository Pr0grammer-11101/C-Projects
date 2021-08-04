#include<stdio.h>
#include<stdlib.h>

// my version of strcat()

void str_cat(char *, char*);

int main(void)
{
	char *s1, *s2;
	int size1, size2;

	printf("enter the length of the first string....");
	scanf("%d", &size1);

	printf("enter the length of the second string....");
	scanf("%d", &size2);

	s1=(char *)malloc(size1);
	s2=(char *)calloc(size1, sizeof(char));

	printf("enter the strings....\n\n");

	printf("String 1-> ");
	scanf("%s", s1);
	printf("\nString 2-> ");
	scanf("%s", s2);

	printf("\nThe strings after concatenating them are.....\n\n\n");

	str_cat(s1, s2);

	free(s1), free(s2);
	return 0;
}


void str_cat(char *s1, char *s2)
{
	printf("%s", s1);
	printf("%s", s2);
	printf("\n\n\n");

}
