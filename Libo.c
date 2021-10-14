#include<stdio.h>
#include<stdlib.h>
#define MAX_ROW 50
#define MAX_COL 50

//Just a mini project
// Got this inspiration from HackerRank while I was trying solve a problem(this one is that problem)
// and ended up creating this bot named "Libo" using static 2d arrays(the problem asked me to use dynamic arrays).
// I will push the same program again after solving using dynamic arrays
int main(void)
{
	int a[MAX_ROW][MAX_COL]={0}, x, y, tmpy=0, n_books=0, n, nm, count=0; 
    // indicator to check if an extra input has been provided by the user while using the "3 x" query.....
	
	printf("Hello! I am Libo the library bot.\n");
	printf("I help customers to donate their books.\n");
	
	printf("Here are the queries that must be used to donate books.\n\n");
	printf("Happy donating!!!!\n\n");
	
	printf("1 x y -> insert a book of y pages at the end of xth shelf.\n");
	printf("2 x y -> print the number of pages in the yth book from the xth shelf.\n");
	printf("3 x -> print the number of books in the xth shelf.\n\n\n");
	
	printf("How many books do you want to donate?? ");
	scanf("%d", &n);
	count=n;
    
    while(count!=0)
    {
        printf("QUERY\n\n");
        printf(">");
        
        scanf("%d", &nm);
        scanf("%d", &x);
        
        if(nm==1)
        {
            scanf("%d",&y);
            if(x<0 || x>MAX_ROW)
            {
                printf("\n\nVALUE TOO LARGE OR SMALL FOR QUERY TO OPERATE!!\n\n");
            }
            
            else
            {
                if(a[x][tmpy]!=0)
                {
                    printf("\n\nIn shelf %d, space occupied, inserting book in the next space....\n\n", x);
                    while(a[x][tmpy]!=0)
                    {
                        tmpy++;
                        if(a[x][tmpy]==0)
                        {
                            a[x][tmpy]=y;
                            printf("\n\nBOOK INSERTION SUCCESSFUL!!!\n\n");
                            break;
                        }
                    }
                    
                    count--;
                }
                
                else
                {
                    a[x][tmpy]=y;
                    
                    printf("\n\nBOOK INSERTION SUCCESSFUL!!!\n\n");
                    count--;
                }
            }
        }
        
        else if(nm==2)
        {
            scanf("%d", &y);
            if(x<0 && y<0)
            {
                printf("\n\nVALUE TOO LARGE OR SMALL FOR QUERY TO OPERATE!!\n\n");
            }
            
            else if(x>MAX_ROW && y>MAX_COL)
            {
                printf("\n\nVALUE TOO LARGE OR SMALL FOR QUERY TO OPERATE!!\n\n");
            }
            
            else if((x<0 || x>MAX_ROW) && (y>=0 && y<=MAX_COL))
            {
                printf("\n\nVALUE TOO LARGE OR SMALL FOR QUERY TO OPERATE!!\n\n");
            }
            
            else if((x>=0 && x<=MAX_ROW) && (y<0 || y>MAX_COL))
            {
                printf("\n\nVALUE TOO LARGE OR SMALL FOR QUERY TO OPERATE!!\n\n");
            }
            
            else
            {
                printf("\n\n%d\n\n", a[x][y]);
            }
        }
        
        else if(nm==3)
        {
            while(a[x][tmpy]!=0)
            {
                tmpy++, n_books++;
            }
            
            printf("\n\n%d\n\n", n_books);
        }
        
        else if(nm>3)
        {
			printf("\n\nERRORNOUS QUERY!!!\n\n");
			exit(0);
        }
        
        tmpy=n_books=0;
    }
    
    printf("\n\nTHANK YOU FOR DONATING BOOKS TO OUR LIBRARY!!!!\n\n");
    
    system("pause");
    
    system("cls");
    
    return 0;
    
    
}
