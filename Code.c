#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

#define mx 100

struct bank
{
    int acno;       /*Account number*/
    char name[50];
    int bal;        /*Balance*/
}b[mx];

int printmenu(void);
void create(void);
void display(void);
void deposit(void);
void withdraw(void);

int noe, i;

main()
{
    char resp = 'y';
    int ch;

    while(toupper(resp)=='Y')
    {
        ch = printmenu();
        switch(ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Invalid entry...");
        }
        printf("Any More Trials?");
        resp=getch();
    }
}

int printmenu(void)
{
    int ch;
    puts("MENU\n");
    puts("1. CREATE\n");
    puts("2. DISPLAY\n");
    puts("3. DEPOSIT\n");
    puts("4. WITHDRAW\n");
    puts("5. EXIT\n");
    printf("Enter the choice = ");
    scanf("%d", &ch);
    return(ch);
}
void create(void)
{
    printf("Enter the number of records = ");
    scanf("%d", &noe);

    for(i=0; i<noe; i++)
    {
        printf("Enter the Account Number = ");
        scanf("%d", &b[i].acno);

        printf("Enter the Name = ");
        scanf("%s", b[i].name);

        printf("Enter the Balance = ");
        scanf("%d", &b[i].bal);
    }
}
void display(void)
{
    printf("ACCOUNT NO.          NAME            BALANCE\n");
    printf("============================================\n");
    for(i=0; i<noe; i++)
        printf("%d               %s                %d\n", b[i].acno, b[i].name, b[i].bal);
}
void deposit(void)
{
    int uamt, uacno; /*User amount & Account no.*/
    printf("Please enter Account No. = ");
    scanf("%d", &uacno);

    for(i=0; i<noe; i++)
    {
        if(b[i].acno==uacno)
        {
            printf("Enter the amount to be deposited = ");
            scanf("%d", &uamt);

            b[i].bal = b[i].bal + uamt;

            printf("Transaction Successful...\n");
            printf("New balance = %d\n", b[i].bal);

            break;
        }
    }
        if(i==noe)
            printf("%d does not exist\n", uacno);
}
void withdraw(void)
{
    int uamt, uacno;
    printf("Enter the Account No. = ");
    scanf("%d", &uacno);

    for(i=0; i<noe; i++)
    {
        if(b[i].acno == uacno)
        {
            printf("Enter the amount for withdrawal = ");
            scanf("%d", &uamt);
            if(b[i].bal - uamt>500)
            {
                b[i].bal = b[i].bal-uamt;

                printf("Transaction Successful...\n");
                printf("Available Balance = %d\n", b[i].bal);

                break;
            }
            else
                printf("Insufficient Balance...");
        }
    }
    if(i==noe)
        printf("%d does not exist\n", uacno);
}
