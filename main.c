#include <stdio.h>
#include<string.h>
#include <stdlib.h>

#define name_size 10
#define address_size 100
#define phone_num_size 11
#define acc_num_size 5
#define num_of_accounts 10

void Menu();
void create();
void update();
void phone(int);
void address(int);
void delet();
void Transactions();
void withdraw(int);
void deposit(int);
void ViewCustomerList();
void CustomerEnquery();

enum status{
    Active = 0,
    Deleted,
    Suspended,
};

struct customer{
	char fname[name_size];
    char dob[10];
    char address[address_size];
    char phone[phone_num_size];
    char accnum[acc_num_size];
	float amount;
    enum status currentStatus;
};

struct customer client[num_of_accounts];
int currIndex = 0;

void CustomerEnquery(){
    int select2;
    printf("1.\tCreate Account\n\n");
    printf("2.\tUpdate an existing Account \n\n");
    printf("3.\tCheck details of an Existing Account\n\n");
    printf("4.\tDelete an existing Account \n\n");
    printf("\tEnter Your choice :");
    scanf("%d", &select2);
    system("cls");
    switch (select2){
        case 1:
            create();
            break;
        case 2:
            update();
            break;
        case 3:
            ViewCustomerList();
            break;
        case 4:
            delet();
            break;
           }
           system("cls");
           Menu();
}

void Menu(){
    int select;

    printf("\t\t\t\t\t\t---Banking Management System 2023--- \n\n");
    printf("\t\t\t\t\t\t\tWelcome to Main Menu\n\n\n\n");
    printf("\t1.Customer Enquiry\n\n");
    printf("\t2.Transactions\n\n");
    printf("\t3.Exit\n\n");


    printf("\tEnter your Choice: ");
    scanf("\n%d", &select);
    system("cls");
    switch(select){
    case 1:CustomerEnquery();
    break;

    case 2:Transactions();
    break;

    case 3:system("cls");
    break;

    }
    }

void create(){

    int num;

    printf("Enter Your Name\t\t:");
    scanf("%s",&(client[currIndex].fname));
    printf("\n\nEnter Your Date of Birth\t:  ");
    scanf("%s",&(client[currIndex].dob));
    printf("\n\nEnter Your address  :\t ");
    scanf("\n%[^\n]s", (client[currIndex].address));
    printf("\n\nEnter Your phone number  :\t  ");
    scanf("%s",&(client[currIndex].phone));
    printf("\n\nEnter Your account number  : \t");
    scanf("%s",&(client[currIndex].accnum));
    printf("\n\nEnter Your amount to deposit  : \t");
    scanf("%f",&(client[currIndex].amount));

    client[currIndex].currentStatus = Active;


    currIndex++;

    printf("\n\n\n\n\t\t\t--Account created successfully!--\n");
    printf("\t\t\tEnter 1 to go to Main Menu : ");
    scanf("%d", &(num));
    system("cls");
    Menu();

    }

void update(){
    int select3;
    char accnum[acc_num_size];
    int num;
    printf("Enter Your Account Number :");
    scanf("%d", &accnum);

   for(int i = 0; i < currIndex; i++){
        if (strcmp(accnum, client[i].accnum) == 0){
            printf("\n\nWhich information to change\n\n");
            printf("1. Phone number\n");
            printf("2. Address\n\n");
            printf("Enter your choice :");
            scanf("%d", &select3);

            switch (select3){
                case 1:
                    phone(i);
                    break;
                case 2:
                    address(i);
                    break;
            }
            return;
        }
    }

    printf("We are sorry, we didn't find your account number. Please try again.\n");
    printf("Exit to main menu");
    scanf("%d",&num);
    system("cls");
    Menu();
    update();
}

void phone(int index){
    char newnum[phone_num_size];
    int num;
    printf("\n\nEnter the new phone number :");
    scanf("%s", newnum);
    strcpy(client[index].phone, newnum);
    printf("\n\n\n\t\t--Your details changed successfully!--\n\n\n\n");

    printf("\t\t\tEnter 1 to go to Main Menu : ");
    scanf("%d", &(num));
    system("cls");
    Menu();
}

void address(int index){
    char newadd[address_size];
    int num;
    printf("Enter the new address :");
    scanf("\n%[^\n]s", newadd);
    strcpy(client[index].address, newadd);
    printf("Address changed successfully!\n");

    printf("\t\t\tEnter 1 to go to Main Menu : ");
    scanf("\n%d", &(num));
    system("cls");
    Menu();
}

void delet(){
    char accountNum[acc_num_size];
    int num;
    printf("Enter the account number to be deleted :");
    scanf("%s", accountNum);

    for(int i = 0; i < currIndex; i++){
        if (strcmp(accountNum, client[i].accnum) == 0){
            client[i].currentStatus = Deleted;
            printf("\n\n\t\t\t--Accout deleted Successfully!--\n");
            printf("\n\nEnter 1 to go to main menu :");
            scanf("%d", &num);
            system("cls");
            Menu();

            return;
        }
    }

    printf("We are sorry, we didn't find your account number. Please try again.\n");

    delet();
}



void Transactions(){
    int transtype;
    char accountNum[acc_num_size];
    printf("Enter the Account Number:\n\n\n");
    scanf("%s", accountNum);
    printf("What do yo want to do :\n");
    printf("1.Withdraw\n");
    printf("2.Deposit\n");
    printf("Enter your choice: ");
    scanf("%d", &transtype);

    for(int i = 0; i < currIndex; i++){
        if ((strcmp(accountNum, client[i].accnum) == 0) && (client->currentStatus == Active)){
            switch (transtype){
            case 1:
                withdraw(i);
                break;
            case 2:
                deposit(i);
                break;
            }
            return;
        }
    }

    printf("We are sorry, we didn't find your account number. Please try again.\n");
    Transactions();
}


void withdraw(int index){
    int amount;
    int num;
    printf("Enter the amount to withdraw :");
    scanf("%d", &amount);
    client[index].amount -= amount;
    printf("Withdrawed successfully\n");

    printf("\t\t\tEnter 1 to go to Main Menu : ");
    scanf("%d", &(num));
    system("cls");
    Menu();
}

void deposit(int index){
    int amount;
    int num;
    printf("Enter the amount to deposit :");
    scanf("%d",&amount);
    client[index].amount += amount;
    printf("Deposited successfully\n");

    printf("\t\t\tEnter 1 to go to Main Menu : ");
    scanf("%d", &(num));
    system("cls");
    Menu();
}

void ViewCustomerList(){
    for (int i = 0; i < currIndex; i++){
        printf("Customer %d\n", i + 1);
        printf("Customer Name: %s\n", client[i].fname);
        printf("Customer Account Balance: %lf\n", client[i].amount);
        printf("Customer Address: %s\n", client[i].address);
        printf("Customer Phone Number: %s\n", client[i].phone);
        printf("Account Status: ");
        switch (client[i].currentStatus)
        {
        case 0:
            printf("Active\n");
            break;

        case 1:
            printf("Deleted\n");
            break;
        }
        printf("\n----------------------------------\n");
    }

    printf("\t\t\tEnter 1 to go to Main Menu : ");
    int num;
    scanf("%d", &(num));
    system("cls");
    Menu();
}

int main(){
    char password[7];
    char Pass[]="group24";
    char retry;
    printf("\n\n\n\n\n\n\t\t\t\tEnter the password to Login : ");
    scanf("%s", &password);
    if(strcmp(password,Pass)==0){
        printf("Login Successful!\n\n");
        system("cls");

        Menu();

    }
    else{
        printf("Login Unsuccessful! Try again");

    }

    return 0;
    }
