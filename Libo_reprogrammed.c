#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 40

// my library record mangement bot.
// program needs more working upon!!!

int main(void)
{
	int **store_books, nm, x, y, tmpy=0, no_of_shelves, books;
	char *query;
	query=(char*)malloc(30);
	
	printf("\n\nHELLO! I am Libo, the library management bot.\nI have been reprogrammed.\n\n");
	printf("\n\nMy task is to maintain records of donators who donated books in the last couple of days to the library.\n\n");
	printf("\n\nQueries that you might want to know in order to donate, \nview and check the number of books that you have donated.\n\n");
	printf("1)\"insert\" \n\"x\" \"y\"  -> insert a book with y pages in the xth shelf.\n");
	printf("2) \"print\" \n\"x\" \"y\"  -> print the number of pages in the yth book in the xth shelf.\n");
	printf("3)\"print_all\" \n\"x\"  -> print the number of books in the xth shelf.\n\n");

	printf("enter the number of shelves: ");
	scanf("%d", &no_of_shelves);
	printf("enter the number of books: ");
	scanf("%d", &books);

	int *no_of_books;

	no_of_books=(int*)malloc(no_of_shelves*sizeof(int));
	for(int i=0; i<no_of_shelves; i++)
	{
		no_of_books[i]=0;
	}

	store_books=(int**)malloc(no_of_shelves*sizeof(int *));

	for(int i=0; i<no_of_shelves; i++)
	{
		store_books[i]=(int*)malloc(MAX*sizeof(int));
	}

	for(int i=0; i<no_of_shelves; i++)
	{
		for(int j=0; j<MAX; j++)
		{
			store_books[i][j]=0;
		}
	}
	
	printf("\n\n\n\nEnter your queries.......\n\n\n");

	getchar();
	
	
	while(books)
	{
		printf("Queries\n\n");
		printf(">");

		gets(query);

		for(int i=0; query[i]!='\0'; i++)
		{
			query[i]=tolower(query[i]);

		}

		if(strcmp(query, "insert")==0)
		{
			scanf("%d%d", &x, &y);
			getchar();

			if(store_books[x][tmpy]!=0)
			{
				printf("\n\nin shelf %d, space occupied, inserting book in the next empty space of shelf %d\n\n", x, x);
				while(store_books[x][tmpy]!=0)
				{
					tmpy++;
					if(store_books[x][tmpy]==0)
					{
						store_books[x][tmpy]=y;
						printf("\n\nBOOK INSERTION SUCCESSFUL!!!!!\n\n");
						no_of_books[x]++;
						break;
					}
				}
			}

			else
			{
				store_books[x][tmpy]=y;
				no_of_books[x]++;
				printf("\n\nBOOK INSERTION SUCCESSFUL!!!\n\n");
			}

			books--;
		}

		else if(strcmp(query, "print")==0)
		{
			scanf("%d%d", &x, &y);
			getchar();
			printf("\n\n%d\n\n", store_books[x][y]);
		}

		else if(strcmp(query, "print_all")==0)
		{
			scanf("%d", &x);
			getchar();
			printf("\n\n%d\n\n", no_of_books[x]);
			
		}

		else
		{
			printf("\n\n\nERRORNOUS QUERY!!!\n\n");
		}


	}

	free(no_of_books);

	free(query);

	for(int i=0; i<no_of_shelves; i++)
	{
		free(store_books[i]);
	}

	free(store_books);

	return 0;
}
