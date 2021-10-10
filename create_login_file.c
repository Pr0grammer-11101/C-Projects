// this program requires to sign up

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct user_details
{
    char user_name[120], user_email[120], user_password[120];
    int age;
};

typedef struct user_details u_d;

u_d u;
int main(void)
{
    char ans;
    int success;
    FILE *f;

    printf("Hello user....Do you want to create your account?(y/n): ");
    scanf("%c", &ans);

    getchar();

    if(ans=='y' || ans=='Y')
    {
        f=fopen("user_details.txt", "wb");
        if(f==NULL)
        {
            printf("\n\n\nCANNOT OPEN FILE!!!\n\n\n");
            exit(0);
        }

        printf("enter your details:\n\n\n");

        printf("Name: ");
        gets(u.user_name);
        printf("Email: ");
        gets(u.user_email);
        printf("Password: ");
        gets(u.user_password);
        printf("Age: ");
        scanf("%d", &u.age);

        success=fwrite(&u, sizeof(u), 1, f);

        if(success==1)
        {
            system("pause");
            system("cls");
            printf("\n\nYour account has been created!!!\n\n");
        }

        else
        {
            printf("\n\nOOPS!! SOMETHING WENT WRONG!!!\n\n");
            exit(0);
        }


        fclose(f);
        
    }  

    else
    {
        printf("\n\nSee you around!!!\n\n");
    }


    return 0;
}