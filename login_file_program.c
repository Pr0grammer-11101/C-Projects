// this program will ask you to sign in to proceed to further
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct user_details
{
    char name[120], email[120], password[120];
    int age;
};

typedef struct user_details u_d;

u_d u;

int main(void)
{
    int option, success;
    char username[120], user_email[120], user_pw[120];
    FILE *f;

    printf("\n\nTo proceed any further you must sign in.\n\n\n ");

    printf("1. Sign in.\n");
    printf("2. New? Sign up.\n");
    printf(">");
    scanf("%d", &option);

    printf("\n\n\n");

    getchar();

    if(option==1)
    {
        f=fopen("user_details.txt", "rb");

        while(fread(&u, sizeof(u), 1, f)==1);

        printf("Name: ");
        gets(username);
        printf("Email id: ");
        gets(user_email);
        printf("Password: ");
        gets(user_pw);

        if(strcmp(u.name, username)==0)
        {
            if(strcmp(u.email, user_email)==0)
            {
                if(strcmp(u.password, user_pw)==0)
                {
                    printf("\n\n\nLOGIN SUCCESSFUL!!!!\n\n");

                }

                else
                {
                    printf("\n\nINVALID EMAIL ID OR PASSWORD!!!!\n\n");
                }
            }

            else
            {
                printf("\n\nINVALID EMAIL ID OR PASSWORD!!!!\n\n");
            }
        }

        else
        {
            printf("Name %s doesnot exist!!!\n\n", username);
        }

        fclose(f);

        
    }

    else if(option==2)
    {
        printf("Please enter your details below:\n\n");

        printf("Name: ");
        gets(u.name);
        printf("Email: ");
        gets(u.email);
        printf("Password: ");
        gets(u.password);
        printf("Age: ");
        scanf("%d", &u.age);

        f=fopen("user_details.txt", "wb");
        if(f==NULL)
        {
            printf("\n\nCANNOT OPEN FILE!!!\n\n");
            exit(0);
        }

        success=fwrite(&u, sizeof(u), 1, f);

        if(success==1)
        {
            printf("\n\nYOUR ACCOUNT HAS BEEN CREATED!!!\n\n");
        }

        else
        {
            printf("\n\nOOPS!! AN ERROR OCCURED!!!\n\n");
        }

        fclose(f);
    }

    else
    {
        printf("\n\nyou have entered an invalid option!!!\n\n");
    }

    return 0;
    
}