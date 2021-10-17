#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/* this is a problem of hackkerank.com, so this is not the Libo program I was talking about, this is just
a solution to the problem
*/

int  main(void)
{
    int total_number_of_queries;
    int **total_number_of_pages, n;

    printf("enter the number of  shelves ");
    scanf("%d", &n);
    printf("enter total number of queries: ");
    scanf("%d", &total_number_of_queries);


    total_number_of_pages=(int**)malloc(n*sizeof(int *));

    for(int i=0; i<n; i++)
    {
        total_number_of_pages[i]=(int*)malloc(40*sizeof(int));
    }
    
    for(int i=0; i<n; i++)
    {
		for(int j=0; j<40; j++)
		{
			total_number_of_pages[i][j]=0;
		}
	}

    int x, y, tmpy=0, nm, j=0;

    // QUERY FOR
    // 1 x y  -> insert a book of y pages in the xth shelf

    for(int i=0; i<n; i++)
    {
		
		while(j<total_number_of_queries)
		{       

			printf("enter your query(type 1):\n\n");

			printf(">");
			scanf("%d", &nm);
			scanf("%d", &x);
			scanf("%d", &y);
			
			j++;
			
			if(j==total_number_of_queries)
			{
				exit(0);
			}
		
        
			if(total_number_of_pages[x][tmpy]!=0)
			{
				printf("\n\nIn shelf %d space occupied. Inserting book in the next emtpy space in shelf %d.....\n\n", x, x);
				while(total_number_of_pages[x][tmpy]!=0)
				{
					tmpy++;
					if(total_number_of_pages[x][tmpy]==0)
					{
						total_number_of_pages[x][tmpy]=y;
						printf("\n\nBOOK INSERTION SUCCESSFUL!!!\n\n");
						break;
					}
					
				}
				
				tmpy=0;
				
			}
			
			else
			{
				total_number_of_pages[x][tmpy]=y;
				printf("\n\nBOOK INSERTION SUCCESSFUL!!!\n\n");
			}
		}
	}
		
		
		for(int i=0; i<n; i++)
		{
			free(total_number_of_pages[i]);
		}
		
		return 0;		        

}
