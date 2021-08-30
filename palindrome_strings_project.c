#include<stdio.h>
#include<stdlib.h>


enum are_palindrome {NO, YES};

int is_palindrome(char*, char*, int, int);
int main(void)
{
	char *s, *_s;
	int j, c=0, palindrome;

	s=(char *)malloc(120);
	_s=(char *)calloc(120, sizeof(char));

	printf("enter a string: ");
	gets(s);

	for(int i=0; s[i]!='\0'; i++)
	{
		c++;
	}

	for(int k=0; s[k]!='\0'; k++)
	{
		for(int i=0; s[i]!='\0'; i++)
		{
			if((int)s[i]>=65 && (int)s[i]<=90)
			{
				s[i]=(char)((int)s[i]+32);
			}

			else if((int)s[i]>=32 && (int)s[i]<=47)
			{
				j=i;
				while(j<c-1)
				{
					s[j]=s[j+1];
					j++;
				}

				s[c-1]='\0';
				c--;
				i=0;
			}

			else if((int)s[i]>=48 && (int)s[i]<=57)
			{
				j=i;
				while(j<c-1)
				{
					s[j]=s[j+1];
					j++;
				}

				s[c-1]='\0';
				c--;
				i=0;
			}

			else if((int)s[i]>=58 && (int)s[i]<=64)
			{
				j=i;
				while(j<c-1)
				{
					s[j]=s[j+1];
					j++;
				}

				s[c-1]='\0';
				c--;
				i=0;
			}

			else if((int)s[i]>=91 && (int)s[i]<=96)
			{
				j=i;
				while(j<c-1)
				{
					s[j]=s[j+1];
					j++;
				}

				s[c-1]='\0';
				c--;
				i=0;
			}

			else if((int)s[i]>=123 && (int)s[i]<=126)
			{
				j=i;
				while(j<c-1)
				{
					s[j]=s[j+1];
					j++;
				}

				s[c-1]='\0';
				c--;
				i=0;
			}
		}
	}

	for(int i=0; s[i]!='\0'; i++)
	{
		_s[i]=s[i];
	}

	_s[c]='\0';

	palindrome=is_palindrome(s, _s, 0, c-1);

	if(palindrome==YES)
	{
		printf("\n\nThe string is palindrome!!\n\n");
	}

	else
	{
		printf("\n\nThe string is not paildrome!!\n\n");
	}

	free(s);
	free(_s);

	return 0;

}

int is_palindrome(char *s, char *_s, int i, int j)
{
	if(s[i]=='\0')
	{
		return YES;
	}

	if(s[i]==_s[j])
	{
		return is_palindrome(s, _s, i+1, j-1);
	}

	else
	{
		return NO;
	}
}