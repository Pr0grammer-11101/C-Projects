#include<stdio.h>

int main(void)
{
	char s1[30], s2[30];
	int is_palindrome=1, are_equal=1;

	printf("enter the first string....");
	gets(s1);

	printf("enter the second string....");
	gets(s2);

	int i=0, count=0;

	while(s2[i]!='\0')
	{
		count++;
		i++;
	}

	i=0;
	while(s1[i]!='\0' && s2[i]!='\0')
	{
		if(s1[i]!=s2[i])
		{
			are_equal=0;
			break;
		}

		i++;
	}

	if(are_equal==0)
		printf("\nthe strings are not equal....\n\n");
	else
		printf("\nthe strings are equal....\n\n");

	i=0;
	while(s1[i]!='\0' && count>=0)
	{
		if(s1[i]!=s2[count-1])
		{
			is_palindrome=0;
			break;
		}
		count--;

		i++;
	}

	if(is_palindrome==0)
		printf("\nthe strings are not palindrome....\n\n");
	else
		printf("\nthe strings are palindrome.....\n\n");

	return 0;
}
