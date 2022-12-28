#include<stdio.h>
#define BUUFER_SIZE 30 
#define FILE_BUFFER 1000
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
#define SAVING_ACCOUNT "SAVING"
#define CURRENT_ACCOUNT "CURRENT"
#define NONE "none"

typedef struct customer_details
{
	char customer_name[BUUFER_SIZE] ;
	long int account_number;
	char phone_number[BUUFER_SIZE] ;
	char email_id[BUUFER_SIZE];
	char address[100] ;
	int savin_balance ;/**need to remove**/
	int current_balance;
	int saving_ac ;
	int current_ac;
	
	struct customer_details *next ;
	
}customer_details;

typedef struct account_details
{
	long int account_no;
	char account_type[15];
	int balance ;
	
	struct account_details *next;
}account_details ;

typedef struct admin_data
{
	
	char user_name[BUUFER_SIZE];
	char pswd[BUUFER_SIZE];
	
	struct admin_data *next ;
}admin_data;

typedef struct transaction_details
{
        int transaction_id;
        int receiver_id;
        char transaction_type[20];
        int amount;
 	int date;
        struct transaction_details *next;
}transaction_details;



customer_details *customer(customer_details *, account_details * , transaction_details *);

customer_details *registration_customer(customer_details *);
void adding_customer_info_to_file();
int account_number_genaration();
customer_details customer_info_extraction_from_file(char * , customer_details);
customer_details* create_list_for_customer(customer_details *, customer_details);
customer_details *customer_login(customer_details * ,long int,char *);
customer_details *customer_menu(customer_details * , customer_details * , account_details * , transaction_details * );
void open_account(customer_details * ,account_details * );
void update_customer_details(customer_details *);
void save_customer_data_into_file(customer_details * ,account_details * );
void Deposite_customer_account(account_details *, transaction_details *);
void withdraw_from_account(account_details *);
void check_balance(account_details *);
int login(admin_data );

admin_data bank_admin_file(admin_data);

customer_details * admin(customer_details *);
void design();
void Display(customer_details *);
customer_details *update_customer_info(customer_details *);


void search_for_customer(customer_details *);
void seach_for_customer_with_name(customer_details *);

customer_details * delete_account_with_bank_id(customer_details *);

int intiger_validation(char *str);

int alpha_validator(char *s);

int password_validation(char *str);

int bank_id_validation(long int );
int phone_validation(char *str);

account_details* account_registration(account_details *);

account_details account_info_extraction_from_file(char * , account_details);

account_details *create_list_for_account(account_details * , account_details);

account_details *get_the_account_number_for_customer(long int ,account_details *);
