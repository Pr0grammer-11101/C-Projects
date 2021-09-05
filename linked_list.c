#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *start, *next, *save;

int main(void)
{
	char ans;
	start=NULL;

	save=(struct node*)malloc(sizeof(struct node));
	printf("enter information about node: ");
	scanf("%d", &save->info);
	start=save;
	save->link=NULL;
	printf("Do you want to continue?: ");
	scanf(" %c", &ans);

	while(ans=='y' || ans=='Y')
	{
		next=(struct node*)malloc(sizeof(struct node));
		save->link=next;
		save=next;
		printf("enter information about node: ");
		scanf("%d", &save->info);
		save->link=NULL;
		printf("Do you want to continue?: ");
		scanf(" %c", &ans);
	}

	printf("\n\nThis is the linked list that you entered.....\n\n\n\n");

	printf("%d->", start->info);
	while(start->link!=NULL)
	{
		start=start->link;
		printf("%d->", start->info);
	}
	printf("NULL\n\n");

	free(save);
	free(next);


	return 0;
}