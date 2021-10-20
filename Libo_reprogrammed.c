#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


int main(void)
{
	int *no_of_books, no_of_shelves, x, y, tmpy=0, **no_of_pages, space, books, nm;
	char ans, *username;

	FILE *f;


	username=(char*)calloc(16, sizeof(char));

	printf("HELLO!! I AM LIBO, THE LIBRARY MANAGEMENT BOT.\n\n");
	printf("I keep track of the names of donators of books.....\n\n");
	printf("\n\nAre you here to donate books?(y/n): ");
	scanf("%c", &ans);
	getchar();

	if(ans=='y' || ans=='Y')
	{
		printf("\n\nThe queries that you will be needing......\n\n");
		printf("\n1 x y -> \"insert a book of y pages in the xth shelf\"\n\n");
		printf("\n2 x y -> \"print the number of pages of yth book in the xth shelf\"\n\n");
		printf("\n3 x -> \"print the number of books in xth shelf\"\n\n");

get_username:


		printf("Please enter your username(if you don't have any please create by entering it(must be 8-16 characters long)): ");
		gets(username);

		if(strlen(username)==0 || strlen(username)>16)
		{
			printf("\n\nUSERNAME TOO LONG!!! ENTER AGAIN!!\n\n");
			goto get_username;
		}

		space=16-strlen(username);

		printf("enter the number of shelves: ");
		scanf("%d", &no_of_shelves);

		printf("enter the number of books: ");
		scanf("%d", &books);

		f=fopen("D:\\Special_projects\\Library_record_file.txt", "a");

		if(f==NULL)
		{
			printf("\n\nCANNOT OPEN FILE!!!\n\n");
			exit(0);
		}

		fprintf(f, "%s", username);

		for(int i=0; i<space; i++)
		{
			fprintf(f, " ");
		}

		fprintf(f, "%d\t", books);

		fclose(f);

		system("echo %time%\t%date% >> D:\\Special_projects\\Library_record_file.txt");


		no_of_books=(int*)calloc(no_of_shelves, sizeof(int));

		no_of_pages=(int**)malloc(no_of_shelves*sizeof(int *));

		for(int i=0; i<no_of_shelves; i++)
		{
			no_of_pages[i]=(int*)calloc(50, sizeof(int)); // max 50 books
		}

		printf("\n\nPlease enter your queries.....\n\n");

		while(books)
		{
			printf("Query>\n\n");
			printf(">");
			scanf("%d", &nm);
			if(nm==1)
			{
				scanf("%d %d", &x, &y);

				if(x<0 || x>no_of_shelves)
				{
					printf("\n\nCANNOT INSERT BOOK!! INVALID VALUE FOR SHELF ENTERED!!!\n\n");
					continue;
				}

				if(no_of_pages[x][tmpy]!=0)
				{
					printf("\nin shelf %d, space occupied, inserting book in next emtpy space in shelf %d\n\n", x, x);
					while(no_of_pages[x][tmpy]!=0)
					{
						tmpy++;
						if(no_of_pages[x][tmpy]==0)
						{
							no_of_pages[x][tmpy]=y;
							printf("\n\nBOOK INSERTION SUCCESSFUL!!!\n\n");
							tmpy=0;
							break;
						}
					}

				}

				else
				{
					no_of_pages[x][tmpy]=y;
					printf("\n\nBOOK INSERTION SUCCESSFUL!!!\n\n");
				}

				

				no_of_books[x]++;
				books--;
			}

			else if(nm==2)
			{
				scanf("%d %d", &x, &y);

				if(x<0 || x>no_of_shelves)
				{
					printf("\n\nCANNOT DISPLAY PAGE NUMBERS!! INVALID SHELF OR BOOK NUMBER ENTERED!!!\n\n\n");
					continue;
				}

				else if(y<0 || y>50)
				{
					printf("\n\nCANNOT DISPLAY PAGE NUMBERS!! INVALID SHELF OR BOOK NUMBER ENTERED!!\n\n\n");
					continue;
				}

				printf("\n\n%d\n\n", no_of_pages[x][y]);
			}

			else if(nm==3)
			{
				scanf("%d", &x);
				if(x<0 || x>no_of_shelves)
				{
					printf("\n\nCANNOT DISPLAY NUMBER OF BOOKS!! INVALID SHELF NUMBER ENTERED!!!\n\n");
					continue;
				}

				printf("\n\n%d\n\n", no_of_books[x]);
			}

			else
			{
				printf("\n\nINAVLID QUERY!!!!\n\n");
				continue;
			}
		}

		
	}


	else
	{
		printf("\n\nI suggest you go to my sister Bibo(Book Incharge Bot) then.\n\n");
	}

	for(int i=0; i<no_of_shelves; i++)
	{
		free(no_of_pages[i]);
	}

	free(no_of_pages);

	free(no_of_books);
	free(username);

	return 0;
}
