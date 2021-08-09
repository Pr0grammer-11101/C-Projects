#include<stdio.h>

void reverse(char[]);

int main(void)
{
	char s[30]="";  // assigning '\0' to each element of character array s
	int count=0, i=0;

	printf("enter a string....");
	gets(s);

	while(s[i]!='\0')  // calculating the length of the string
	{
		count++;
		i++;
	}

	s[count]=' '; // automatically assigning a whitespace at the end

	printf("\nThe reverse string is....\n\n");

	reverse(s);

	return 0;
}

void reverse(char s[])
{
	int i, j, k;
	j=0;
	char s2[30]="";
	i=0;
	while(s[i]!='\0')
	{

		if(s[i]==' ')
		{
			k=i-1;
			while(s[k]!=' ')
			{
				s2[j]=s[k];

				k--, j++;

				if(k<0)
					break;
			}
			s2[j]=' ';
			j++;
		}
		i++;
	}

	i=0;

	while(s2[i]!='\0')
	{
		printf("%c", s2[i]);
		i++;
	}

}
