#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *adv;
};

typedef struct node Node;

Node *start, *save, *next, *end;

int main(void)
{
    char ans;

    start=NULL;
    save=(Node*)malloc(sizeof(Node));

    printf("enter node information: ");
    scanf("%d", &save->info);

    start=save;

    save->prev=NULL;
    save->adv=NULL;
    printf("do you want to enter more?(y/n): ");
    scanf(" %c", &ans);

    while(ans=='y' || ans=='Y')
    {
        next=(Node*)malloc(sizeof(Node));
        printf("enter node information: ");
        scanf("%d", &next->info);
        next->prev=save;
        next->adv=NULL;
        save->adv=next;
        save=next;

        printf("do you want to enter more?(y/n): ");
        scanf(" %c", &ans);
    }

    end=next;

    printf("\n\nthis is your circular linked list....\n\n");

    start->prev=end; // connecting the first node with last node
    end->adv=start; // connecting the last node with first node

    save=start;

    while(save)
    {
        printf("%d->", save->info);
        save=save->adv;

        if(save==start)
        {
            printf("%d->", save->info);
            break;
        }
    }

    printf("\n\nthis is your circular linked list in reverse order....\n\n");

    save=end;

    while(save)
    {
        printf("%d->", save->info);
        save=save->prev;
        
        if(save==end)
        {
            printf("%d->", save->info);
            break;
        }
    }

    free(save);
    free(next);
}