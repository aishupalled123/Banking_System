#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"banking_prototype.h"

customer_details * admin(customer_details *c_root)
{
	
	int ch  , exit_flag = 0;
	char temp[BUUFER_SIZE];
	admin_data admin_root  = bank_admin_file(admin_root);
	
	if(login(admin_root))
	{
		printf("------------WLECOME TO ADMIN MODULE--------------------\n");
		
		while(1)
		{
			design();
			printf("1) View Coustmers\n");
			printf("2) Update Coustmers\n");
			printf("3) search Coustmer\n");
			printf("4) Delete Coustmers\n");
			printf("5) exit\n");
			design();
			while(1)
			{
				scanf("%s",temp);
				if(intiger_validation(temp) == 0)
				{
					ch = atoi(temp);
					if(ch >= 1 && ch <= 5)
					{
						ch = atoi(temp);
						break;
					}
					else 
						printf("enter number with range of 1 to 5 \n");
					
				}
				else
					printf("enter valid input\n");
			}
	
			switch(ch)
			{
				case View_Coustmers :
					Display(c_root);
					break;
				case Update_Coustmers :
					c_root = update_customer_info(c_root);
					save_customer_data_into_file(c_root , NULL);
					break;
				case search_Coustmer :
					printf("1) for Bank-id\n");
					printf("2) For Account Holder name\n");
					while(1)
					{
						scanf("%s",temp);
						if(intiger_validation(temp) == 0)
						{
							ch = atoi(temp);
							if(ch >= 1 && ch <= 2)
							{
								
								ch = atoi(temp);
								break;
							}
							printf("enter number with range of 1 to 2 \n");
						}
						else
							printf("enter valid input\n");
					}
					switch(ch)
					{
						case  seach_id :
							search_for_customer(c_root);
							break;
						case search_name :
							seach_for_customer_with_name(c_root);
							break;
					}
					break;
					
				case Delete_Coustmers :
					c_root = delete_account_with_bank_id(c_root);
					save_customer_data_into_file(c_root , NULL);
					    break;
				case exit_1 :
					exit_flag = 1;
			}
			
			if(exit_flag == 1)
				break;
		}	
	}
	else
	{
		printf("please cheack the login credentials\n");
	}
	
}

int login(admin_data admin_root)
{

	char user[BUUFER_SIZE] ;
	char password[BUUFER_SIZE];
	
	int admin_pswd_flag = 0 ;
	while(1)
	{
	
		printf("enter the usr name \n");
		while(1)
		{
			getchar();
			fgets(user , 20 , stdin);
			user[strlen(user)-1] = '\0';
			
			if(alpha_validator(user))
				break;
			else
				printf("use only characters\n");
		}
		
			
		printf("enter the password\n");
		while(1)
		{
			scanf("%s",password);
			
			if(password_validation(password))
				break;
			else 
				printf("enter the correct password\n");	
		}	
		
		if(strcmp(admin_root.user_name ,user ) == 0)
		{
			if(strcmp(admin_root.pswd ,password ) == 0)
			{
				return 1;
				
			}
		}
		else 
		{
			admin_pswd_flag++;
			printf("please enter correct Password \n");
		}
		
		if(admin_pswd_flag == 3)
		{
			
			printf("Too many attempts please try again\n");
			return 0;
		}
		
	}
	
}
admin_data bank_admin_file(admin_data source)
{
	char *str = "admin_info.txt";
	
	FILE *fptr = NULL ;
	char *piece ;
	char buffer[FILE_BUFFER];
	int index = 1;
	fptr = fopen(str,"r");
	
	if(fptr == NULL)
	{
		printf("%s file opening error\n",str);
		
	}	
	else 
	{
		while(!feof(fptr))
		{
		
			if(!(fgets(buffer,FILE_BUFFER,fptr)))
			{
				//printf("string reading is fail\n");
				break ;
			}
			else 
			{
				piece = strtok(buffer,",");
				while(piece !=NULL)
				{
					
					//printf("str :%s\n",piece);
					if(index == 1)
					{
						strcpy(source.user_name ,piece );
						source.user_name[strlen(source.user_name)] = '\0';
						index = 2;	
					}
					else if(index == 2)
					{
						strcpy(source.pswd ,piece );
						source.pswd[strlen(source.pswd)-1] = '\0';
					}
					piece = strtok(NULL,",");
				}
			}	
			
		}
	}
return source ;	
}	


customer_details *update_customer_info(customer_details *c_root)
{
		
	long int customer_id = 0 ;
	char coutomer_pswd[15];
	
	customer_details *user = NULL;	
	while(1)
	{
		printf("enter coustomer-id \n");
		scanf("%ld",&customer_id);
		if(bank_id_validation(customer_id))
			break;
		else
			printf("please enter valid bank-id");
	}
	printf("enter the password\n");
	while(1)
	{
		getchar();
		fgets(coutomer_pswd,15,stdin);
		coutomer_pswd[strlen(coutomer_pswd)-1] = '\0';
		if(phone_validation(coutomer_pswd) )
			break ;
		else
			printf("enter correct phone number\n");
	}

	if(user = customer_login(c_root ,customer_id,coutomer_pswd ))
	{
			update_customer_details(user);
			
	}
	else 
	{
		printf("wrong credentials please try agina\n");
	}
	
}

void search_for_customer(customer_details *p)
{
	long int customer_id = 0 ;
	while(1)
	{
		printf("enter coustomer-id \n");
		scanf("%ld",&customer_id);
		if(bank_id_validation(customer_id))
			break;
		else
			printf("please enter valid bank-id");
	}
	while(p!=NULL)
	{
		if(p->account_number == customer_id)
		{
			Display(p);
			break;
		}
		p = p->next ;
	}

}

void seach_for_customer_with_name(customer_details *p)
{
	char coutomer_name[15];
	printf("enter the customer name\n");
	
		
	while(1)
	{
		getchar();
		fgets(coutomer_name,15,stdin);
		coutomer_name[strlen(coutomer_name)-1] = '\0';
		if(alpha_validator(coutomer_name))
			break;
		else
			printf("use only characters\n");
	}
	while(p!=NULL)
	{
		if(strcmp(p->customer_name,coutomer_name )==0)
		{
			Display(p);
		}
		p = p->next ;
	}		
}


int *lookup(customer_details *source, int prod_id , int *index )
{
	
	
	 int count = 1 , check_flag = 0;
	 
	 if(source ==  NULL)
	 {
		printf("list is empty\n") ;
		return NULL ;
	  }
	
	customer_details *p = source ;
	
	int i = 0 , j =0;
	
	while(p!=NULL)
	{
		if(p->account_number  == prod_id)
		{
			Display(p);	
			check_flag = 1;
			break;
		}
		else 
		{
			count++ ;
				
		}
		p = p->next ;
	}
	
	if(check_flag == 1)
	{
		*index = count ;
	}
	else
		*index = -1;
	
	return index ;
}

int* len_of_list(customer_details  *source ,int *index)
{
	int count =0 ;
	
	if(source ==  NULL)
	{
		printf("list is empty\n") ;
		return NULL ;
	}
	
	
	customer_details   *p = source ;
	
	while(p!=NULL)
	{
		count ++;	
		p = p->next ;
	}
	
	*index = count ;
	
	return index ;	
}

customer_details * delete_account_with_bank_id(customer_details *source)
{
	int position = 0   , len = 0 , link =1;
	char ch ;
	long int customer_id = 0 ;
	
	if(source ==  NULL)
	{
		printf("list is empty\n") ;
		return NULL ;
	 }
	
	printf("enter coustomer-id \n");
	scanf("%ld",&customer_id);
	 
	 
	customer_details *p = source ;
	customer_details *temp = source  ;
	
	position = *lookup(p,customer_id,&position) ; 
	len = *len_of_list(p,&len);
	

	printf("please enter y to delete \n");
	scanf(" %c",&ch);
	
	if((ch == 'y' || ch == 'Y')&&position >0)
	{
		if(position == 1)
		{
			source = temp->next ;
			temp->next = NULL ;
		}
		else if(position < len)
		{
				 
			while(link < position-1)
			{
				temp = temp->next;
				link++ ;
					
			}
			
			customer_details* del = temp->next;
			del->next = del->next ;
			temp->next = del->next ;		
			
		}
		else if(position == len)
		{
			link = 1 ;
			
			
			while(link < position-1)
			{
				temp = temp->next; 
				link++;
			}
			
			temp->next = NULL;
			
		
		}
	}
	else 
	printf("Bank-id  is  not deleted\n");

return source;
	
}
