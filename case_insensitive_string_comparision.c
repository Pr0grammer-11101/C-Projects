#include<stdio.h>

int cmp_str(char[], char[]);

int main(void)
{
	char str1[30], str2[30];
	int result;

	printf("enter two strings.....\n\n");

	printf("String 1-> ");
	gets(str1);

	printf("String 2-> ");
	gets(str2);

	result=cmp_str(str1, str2);

	if(result==0)
		printf("\nThe strings are equal!!!\n\n");

	else
		printf("\nThe strings are not equal!!!\n\n");


	return 0;
}

int cmp_str(char s1[], char s2[])
{
	int i=0;
	while(s1[i]!='\0' || s2[i]!='\0')
	{
		if((int)s1[i]>(int)s2[i])
		{
			if((int)s1[i]-(int)s2[i]==32)
			{
				i++;
			}

			else if((int)s1[i]-(int)s2[i]==0)
			{
				i++;
			}

			else
			{
				return -1;
			}
		}

		else
		{
			if((int)s2[i]-(int)s1[i]==32)
			{
				i++;
			}

			else if((int)s2[i]-s1[i]==0)
			{
				i++;
			}

			else
			{
				return -1;
			}

		}
	}

	return 0;
}
