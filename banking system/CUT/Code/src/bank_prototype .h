/*************************PRE PRIOCESSOR DIRECTIVES*******************************

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

******************************************************************************/

/***********************DEFINING MACROS**********************************
#define BUUFER_SIZE 30
#define open_acount 1
#define update_details 2
#define deposite 3
#define with_draw 4
#define check_balance_acount 5
#define exit 6

#define View_Coustmers 1
#define Update_Coustmers 2
#define search_Coustmer 3
#define Delete_Coustmers 4

#define exit_1 5
#define seach_id 1
#define search_name 2
#define Account_type 3

***********************************************************************/
typedef struct customer_details                            // DEFINING STRUCTURE customer_details
{
     int cust_id;
     char cust_name[BUFFER_SIZE];
     char phone_number[BUUFER_SIZE] ;
     char email_id[BUUFER_SIZE];
     char address[100] ;
     struct customer_details *next ;

}customer_details;

typedef struct account_details                          //DEFINING STRUCTURE account_details
{
    int cust_id;
    long int account_number;
    char account_type[20];
    int balance;
    struct account_details *next;
}account_details;

typedef struct transaction_details                    //DEFINING STRUCTURE transaction_details
{
        int transaction_id;
        int receiver_id;
        char transaction_type[20];
        int amount;
 int date;
        struct transaction_details;
}transaction_details;

/**********************************FUNCTION DECLARATION****************************/


customer_details *cust_details(customer_details *);

customer_details *registration_customer(customer_details *);
void adding_customer_info_to_file(int);
int account_number_genaration();
customer_details customer_info_extraction_from_file(char * , customer_details);
customer_details* create_list_for_customer(customer_details *, customer_details);
customer_details *customer_login(customer_details * ,long int,char *);
customer_details *customer_menu(customer_details * , customer_details *, account_details * );
void open_account(customer_details *,account_details);
void update_customer_details(customer_details *.account_details*);
void save_customer_data_into_file(customer_details *,account_details*);
void Deposite_customer_account(account_details);
void withdraw_from_account(account_details *);
void check_balance(account_details *);

void admin();
void design();
void Display(customer_details *);
account_details* account_registration(account_details*);

account_details account_info_extraction_from_file(char * , account_details);

account_details *create_list_for_account(account_details * , account_details);

account_details *get_the_account_number_for_customer(long int ,account_details *);