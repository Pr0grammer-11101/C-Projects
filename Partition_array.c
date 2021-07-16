#include<stdio.h>

void Partition(int[], int);

void main()
{
	int a[30], size, i;

	printf("Enter the size of the array.....");
	scanf("%d", &size);

	printf("Enter elements into the array....\n\n");

	i=0;

	while(i<size)
	{
		scanf("%d", &a[i]);

		i++;
	}

	Partition(a, size);

	return;
}

void Partition(int a[], int s)
{
	int i=-1, j=i+1, temp, pointer;

	pointer=a[s-1];

	while(j<s-1)
	{
		if(a[j]<pointer)
		{
			i++;
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}

		j++;
	}

	int index;

	i=0;
	while(i<s-1)
	{
		if(a[s-1]>=a[i] && a[s-1]<=a[i+1])
		{
			index=i+1;
			break;
		}

		i++;
	}

	i=s-1;

	while(i>index)
	{
		a[i]=a[i-1];
		i--;
	}

	a[index]=pointer;

	printf("\n\nPrinting the array after partitioning it.....\n\n\n");

	i=0;

	while(i<s)
	{
		printf("%d ", a[i]);
		i++;
	}

}
