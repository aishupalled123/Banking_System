#include<stdio.h>
#include<stdlib.h>
#include"banking_prototype.h"


void design()
{
	for(int i = 0 ; i < 30 ; i++)
		printf("*");
	
	printf("\n");
}

int main()
{
	int ch  , exit_flag = 0;
	char temp[BUUFER_SIZE];
	design();
	printf("WELL COME TO BANKIN SYSTEM\n");
	design();
	struct customer_details *c_root = NULL;
	struct account_details *ac_root = NULL;
	struct transaction_details *t_root = NULL;
	
	c_root = registration_customer(c_root);
	ac_root = account_registration(ac_root);
	
	while(1)
	{
		design();
		printf("1) Admin\n");
		printf("2) Login as customer\n");
		printf("3) Register as customer\n");
		printf("4) Exit\n");
		design();
		while(1)
		{
			scanf("%s",temp);
			if(intiger_validation(temp) == 0)
			{
				ch = atoi(temp);
				if(ch >= 1 && ch <= 4)
				{
					
					ch = atoi(temp);
					break;
				}
				else 
				printf("enter number with range of 1 to 4 \n");
				
			}
			else
				printf("enter valid input\n");
		}
		
		switch(ch)
		{
			case 1:
				c_root = admin(c_root);
				break ;
			case 2:
				c_root = customer(c_root ,ac_root , t_root);
				break ;
			case 3:
							
				adding_customer_info_to_file();
				c_root = NULL;
				c_root = registration_customer(c_root);
				ac_root = NULL;
				ac_root = account_registration( ac_root );
				
				break ;
			case 4: 
				exit_flag = 1;
				break;
				
		}
		
		if(exit_flag == 1)
		 break;
	}
}
