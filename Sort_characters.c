#include<stdio.h>
#include<stdlib.h>

char alpha[]="abcdefghijklmnopqrstuvwxyz";

// program to sort characters in case insensitve way
void check_uppers(char *, int);
void sort(char *, int *, int);
void main(void)
{
    char *s;

    int count=0;

    s=(char *)malloc(120);

    if(s==NULL)
    {
        printf("\n\nNot enough space!!!\n\n");
    }

    else
    {

        printf("enter a string...");
        gets(s);

        for(int i=0; s[i]!='\0'; i++)
        {
            count++;
        }

        check_uppers(s, count);
    }

    free(s);
    

}


void check_uppers(char *s, int count)
{
    int *ascii, i, j, k=0;

    ascii=(int *)calloc(120, sizeof(int));

    i=0;

    while(s[i]!='\0')
    {
        j=0;
        while(alpha[j]!='\0')
        {
            if((int)alpha[j]-(int)s[i]==32)
            {
                s[i]=alpha[j];  // converting the uppercase character to lowercase and storing it in ascii
                ascii[k]=s[i];
                k++;
            }

            j++;
        }

        i++;
    }

    sort(s, ascii, count);

    free(ascii);

}

void sort(char *s, int *ascii, int count)
{
    int i, j, k=0, temp;

    i=0;
    while(s[i]!='\0')
    {
        j=0;
        while(j<count-1)
        {
            if((int)s[j]>(int)s[j+1])
            {
                temp=(int)s[j];
                s[j]=s[j+1];
                s[j+1]=(char)temp;
            }

            j++;
        }

        i++;
    }

    i=0;
    while(s[i]!='\0')
    {
        if((int)s[i]==ascii[k])
        {
            s[i]=(char)((int)s[i]-32);  // re-converting the lowercase-converted characters to uppercase
            k++;
        }

        i++;
    }

    printf("\nThe string after sorting it is....\n\n");

    puts(s);

    
}