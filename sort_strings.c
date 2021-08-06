#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int num, i=0, j;
	
	printf("how many strings do you want to enter?_");
	scanf("%d", &num);
	
	int length[num];
	
	char *s[num];
	
	printf("enter the length of each string....\n\n");
	
	while(i<num)
	{
		printf("length of string %d-> ", i+1);
		scanf("%d", &length[i++]);
	}
	
	
	i=0;
	while(i<num)
	{
		s[i]=(char *)malloc(length[i]);
		i++;
	}
	
	printf("\nenter the strings.....\n\n");
	
	i=0;
	while(i<num)
	{
		printf("String %d-> ", i+1);
		scanf("%s", s[i]);
		i++;
	}
	
	printf("\nNow we will sort the strings.....\n\n");
	
	
	char *temp;
	
	i=0;
	while(i<num)
	{
		j=0;
		while(j<num-1)  // bubble sort
		{
			if((int)s[j][0]>(int)s[j+1][0])  // compares the 0th characters of each string
			{
				temp=s[j];  // here we are swapping the base addresses
				s[j]=s[j+1];
				s[j+1]=temp;
			}
			
			j++;
		}
		
		i++;
	}
	
	printf("\nThe sorted strings are....\n\n");
	
	i=0;
	
	while(i<num)
	{
		printf("%s\n", s[i]);
		i++;
	}
	
	i=0;
	while(i<num)
	{
		free(s[i]);
		i++;
	}
	
	return 0;
}