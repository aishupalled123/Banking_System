#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>


/********************************************************************************************
* FUNCTION NAME   : bank_id_validation
* DESCRIPTION     : This function checks the validation for bank_id
* PARAMETERS      : num
* RETURN TYPE     : int
**********************************************************************************************/ 

int bank_id_validation(long int num)
{
	int count = 0 ;
	
	while(num>0)
	{
		num /=10;
		count++;
	}
	if(count >=5)
		return 1;
	else 
		return 0;
}

/********************************************************************************************
* FUNCTION NAME   : integer_validation
* DESCRIPTION     : This function checks the validation for integer
* PARAMETERS      : str
* RETURN TYPE     : int
**********************************************************************************************/ 

int intiger_validation(char *str)
{
	long int num ;

	int len =0 , count = 0;
	
	num = atoi(str);
	
	len = strlen(str);
	
	if(num <= 0)
	{
		return 1;
	}
	else
	{	
		do {
		
			num /= 10;
			++count;
			
		  }while(num != 0);
		  
		  if(len == count)
		  	return 0;
		  else 
		  	return 1;	
        }
}

/********************************************************************************************
* FUNCTION NAME   : alpha_validation
* DESCRIPTION     : This function checks the validation for name.
* PARAMETERS      : s
* RETURN TYPE     : int
**********************************************************************************************/ 

int alpha_validator(char *s)
{

        //validation for alphabets
        for(char *p=s;*p!='\0';p++)
        {
                if((!isalpha(*p)) && (*p!=' '))
                        return 0;
        }
        //validation for length
        if(strlen(s)>15 || strlen(s) < 2)
        {
                printf("Enter name within the length of 6 to 15\n");
                return 0;
        }
        return 1;
}

/********************************************************************************************
* FUNCTION NAME   : gender_validation
* DESCRIPTION     : This function checks the validation for gender
* PARAMETERS      : ch
* RETURN TYPE     : int
**********************************************************************************************/ 

int gender_validator(char ch)
{
	if(ch == 'm' || ch == 'f' || ch == 'M' || ch == 'F' )
		return 1;
	else 
		return 0;
}

/********************************************************************************************
* FUNCTION NAME   : phone_validation
* DESCRIPTION     : This function checks the validation for phone number.
* PARAMETERS      : str
* RETURN TYPE     : int
**********************************************************************************************/ 

int phone_validation(char *str)
{
	
	long int num ;

	int len =0 , count = 0;
	
	len = strlen(str);
	
	
	
	
	
	if(num <= 0 || len < 10 || len > 10)
	{
		return 0;
	}
	else
	{
		num = atoi(str);	
		do {
		
			num /= 10;
			++count;
			
		  }while(num != 0);
		  
		  if(len == count)
		  	return 1;
		  else 
		  	return 0;	
        }	
}

/********************************************************************************************
* FUNCTION NAME   : point validation
* DESCRIPTION     : This function checks the validation for point
* PARAMETERS      : str
* RETURN TYPE     : int
**********************************************************************************************/ 

int point_validation(char str)
{
	
	if(str =='A' ||str =='B'||str == 'C' ||str == 'D'||str=='D' ||str== 'E')
		return 1;
	else 
	 return 0;
	
}

/********************************************************************************************
* FUNCTION NAME   : password_validation
* DESCRIPTION     : This function checks the validation for password
* PARAMETERS      : str
* RETURN TYPE     : int
**********************************************************************************************/ 

int password_validation(char *str)
{
	char *ptr = str ;
	
	int c_count = 0 , s_count = 0 , i_count = 0;
	
	while(*ptr !='\0')
	{
		if(*ptr >= 'A' && *ptr <= 'Z')	
		{
			c_count = 1;	
			//printf("Capital\n");
		}
		else if(*ptr >= 'a' && *ptr <= 'z')
		{
			s_count = 1;
			//printf("small\n");
		}
		else if(*ptr >= 48 && *ptr <= 58 )
		{
			i_count = 1;
			//printf("num\n");
		}
		else 
		{
			printf("special characters are not allowed\n");
			return 0;
		}
		
		ptr++;
	}
	
	if(c_count &&s_count &&i_count )
	return 1;
	else 
	return 0;
}


