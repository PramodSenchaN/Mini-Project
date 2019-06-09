#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// Structure declaration
struct acc_type
{
     char bank_name[20];
     char bank_branch[20];
     char acc_holder_name[30];
     int acc_number;
     float available_balance;
};
struct acc_type account[20];

int num_acc;

void Create_new_account();
void Cash_Deposit();
void Cash_withdrawl();
void Account_informations();
void display_options();
void tranfer();

/* main program */
int main()
{   int a = 1;
    char option;
    printf("\n***** Welcome to Bank Application *****\n");
    getch();
    num_acc=0;
    while(1)
    {
       display_options();
       printf("Please enter any options (1/2/3/4/5) ");
       printf("to continue : ");

        option = getch();
        printf("%c \n", option);
        switch(option)
        {
          case '1': system("cls");
                    Create_new_account(a);
                    a++;
                    break;
          case '2': system("cls");
                    Cash_Deposit();
                    break;
          case '3': system("cls");
                    Cash_withdrawl();
                    break;
          case '4': system("cls");
                    Account_information();
                    getch();
                    break;
          case '5': system("cls");
                    transfer();
                    getch();
                    break;
          case '6': return 0;
          default :
                    printf("Please enter one of the options");
                    printf("(1/2/3/4/5/6) to continue \n ");
                    getch();
                    break;
        }
    }
    return 0;
}

/*Function to display available options in this application*/
void display_options()
{
    system("cls");
    printf("\nMenu Options\n");
    printf("\n1. Create new account \n");
    printf("\n2. Cash Deposit \n");
    printf("\n3. Cash withdrawl \n");
    printf("\n4. Account information \n");
    printf("\n5. Transfer \n");
    printf("\n6. Log out \n");
    printf("\n\n");
}

/* Function to create new account */
void Create_new_account(int acc_number)
{
   char bank_name[40]="state_bank";
   char bank_branch[20];
   char acc_holder_name[30];
   int b[20];
  // int acc_number;
   float available_balance = 0;
   fflush(stdin);
   //printf("\nEnter the bank name              : ");
//   bank_name="state_bank";
   //gets(bank_name);
   printf("\nEnter the bank branch            : ");
   gets(bank_branch);
   printf("\nEnter the account holder name    : ");
   gets(acc_holder_name);
   printf("\n Enter the phone number           :");
   scanf("%d",&b);
  // printf("\nEnter the account number(1 to 10): ");
  // scanf("%d", &acc_number);

   strcpy(account[acc_number-1].bank_name, bank_name);
   strcpy(account[acc_number-1].bank_branch, bank_branch);
   strcpy(account[acc_number-1].acc_holder_name, acc_holder_name);
   account[acc_number-1].acc_number = acc_number;
   account[acc_number-1].available_balance = available_balance;

   printf("\nAccount has been created successfully \n\n");
   printf("Bank name              : %s \n" , account[acc_number-1].bank_name);
   printf("Bank branch            : %s \n" , account[acc_number-1].bank_branch);
   printf("Account holder name    : %s \n" , account[acc_number-1].acc_holder_name);
   printf("Account number         : %d \n" , account[acc_number-1].acc_number);
   printf("Available balance      : %.2f \n" , account[acc_number-1].available_balance);
    getch();
   //num_acc++;
}

// Displaying account informations
void Account_information()
{
     register int num_acc = 0;
     //if (!strcmp(customer,account[count].name))
     while(strlen(account[num_acc].bank_name) > 0)
     {
         printf("\nBank name                : %s" , account[num_acc].bank_name);
         printf("\nBank branch              : %s" , account[num_acc].bank_branch);
         printf("\nAccount holder name      : %s" , account[num_acc].acc_holder_name);
         printf("\nAccount number           : %d" , account[num_acc].acc_number);
         printf("\nAvailable balance        : %.2f \n\n" , account[num_acc].available_balance);
         num_acc++;
     }

     getch();
}

// Function to deposit amount in an account

void Cash_Deposit()
{
    system("cls");
    auto int acc_no;
    float money;

   printf("Enter account number you want to deposit money into: ");
   scanf("%d", &acc_no);
   printf("\nThe current balance for account %d is %.2f \n", acc_no, account[acc_no-1].available_balance);
   do
   {
        printf("\nEnter money you want to deposit :  ");
        scanf("%f", &money);
        if(money > 50000 || money <= 0 )
            printf("Amount cannot be deposited. \nEnter amount within the limit. \n");
   }
   while(money > 50000 || money <= 0 );

   while (acc_no = account[acc_no-1].acc_number)
   {
         account[acc_no-1].available_balance += money;
         printf("\nThe New balance for account %d is %.2f \n", acc_no, account[acc_no-1].available_balance);
         break;
   }
   acc_no++;
   getch();
}

// Function to withdraw amount from an account

void Cash_withdrawl()
{
    int acc_no;
   float money;

   printf("Enter account number you want to withdraw money from: ");
   scanf("%d", &acc_no);
   printf("\nThe current balance for account %d is %.2f \n", acc_no, account[acc_no-1].available_balance);

        printf("\nEnter money you want to withdraw :  ");
        scanf("%.2f", &money);


      do
   {
        printf("\nEnter money you want to withdraw :  ");
        scanf("%.2f", &money);
        if(money > 50000 || money > account[acc_no-1].available_balance)
            printf("Amount cannot be withdrawn. \nEnter amount within the limit. \n");
   }while(money > 50000 || money > account[acc_no-1].available_balance);




   while(acc_no = account[acc_no-1].acc_number)
   {
         account[acc_no-1].available_balance -= money;
         printf("\nThe New balance for account %d is %.2f \n", acc_no, account[acc_no-1].available_balance);
         break;
   }



   acc_no++;
   getch();
}





void transfer()

{   int acc_no,acc_no1,money;
    printf("Enter the account from which you wanna transfer\n");
    scanf("%d",&acc_no);
     while(acc_no = account[acc_no-1].acc_number)


     {   printf("Enter the amount you wanna transfer\n");
         scanf("%d",&money);



         if(account[acc_no-1].available_balance>=money)
            {
             printf("Your %d Rs successfully transfered \n",money);
             account[acc_no-1].available_balance -= money;


            }
            else
            {
                printf("You don't have sufficient balance \n");


            }

         printf("\nThe New balance for account %d is %.2f \n", acc_no, account[acc_no-1].available_balance);
         break;

   }
   acc_no++;


   printf("Enter the account you want to transfer\n");
    scanf("%d",&acc_no);
     while(acc_no = account[acc_no-1].acc_number)


     {
         account[acc_no-1].available_balance += money;
         printf("\nThe New balance for account %d is %.2f \n", acc_no, account[acc_no-1].available_balance);
         break;
   }
   acc_no++;
   getch();
}

