#include<stdio.h>

void Tower(int, char, char, char);

int main(void)
{
	int discs;

	printf("enter the number of discs....");
	scanf("%d", &discs);

	Tower(discs, 'A', 'B', 'C');

	return 0;
}

void Tower(int dsk, char s, char t, char d)
{
	if(dsk==1)
	{
		printf("\nMove disc %d from %c to %c......\n", dsk, s, d);
		return;
	}

	Tower(dsk-1, s, d, t);
	printf("\nMove disc %d from %c to %c......\n", dsk, s, d);
	Tower(dsk-1, t, s, d);
}