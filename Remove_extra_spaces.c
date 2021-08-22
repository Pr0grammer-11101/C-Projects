#include<stdio.h>
#include<stdlib.h>


void remove_spaces(char *, int);
int main(void)
{
    char *s;

    int count=0;

    s=(char *)malloc(120);

    printf("enter a string....");
    gets(s);

    for(int i=0; s[i]!='\0'; i++)
    {
        count++;
    }

    remove_spaces(s, count);

    return 0;
}


void remove_spaces(char *s, int l)
{
    int i, j, space_count=0;

    i=0;

    while(s[i]!='\0')
    {
        if(s[i]==' ')
        {
            space_count++;
            if(space_count==2)  // if there are more than 1 whitespaces
            {
                j=i;
                while(j<l-1)
                {
                    s[j]=s[j+1];
                    j++;
                }

                s[l-1]='\0';
                l-=1;
                i=0;
                space_count=0;
            }

            if(s[i+1]!=' ')
            {
                space_count=0;
            }

            else
            {
                ;
            }
        }

        i++;
    }

    printf("\n\nThe string after removing the extra spaces is....\n\n");
    puts(s);

}