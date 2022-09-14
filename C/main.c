/*********************************This is Programed by****************************
************************************Mohaned Assem*********************************
************************************Main program**********************************
**********************************************************************************/

#include "Bank.h"

void main(void)
{
	while (1)
	{
	do
	{
		printf("\t(1) Admin window \n\t(2) Client window \n\t(3) Exit System\n\nNumber: ");
		scanf("%d",&Window);
		fflush(stdin);
		if(Window == 1 || Window == 2 || Window == 3)
		{
			Window_flag = 1 ;
		}
		else
		{
			printf("\n\t\t\t you have choose Wrong option please try again\n\n ");
			Window_flag = 0 ;
		}
	}while(Window_flag != 1);
	
	
	/*admin window*/ 

	if (Window==AdminWindow)
	{
		/*admin : user and password*/
		printf("please enter admin username: ");
		scanf("%s",Admin_Username);
		fflush(stdin);
		printf("please enter admin password: ");
		scanf("%s",Admi_Password);
		
		/*loop for Admin window*/
		while (1)
		{
			/*check if username or password is wrong to enter it again*/
			if (!USER_PASS_CHECK(AdminUser,Admin_Username) || !USER_PASS_CHECK(AdminPass,Admi_Password))
			{
				printf ("\n\t\tyou have entered invalid user or password , please try again\n\n");
				break;
			}	
			
			/*asking user about desired sub windows*/
			printf("\n\t\t\t\twelcome to admin window");
			printf("\n\t(1) Create New Account\n\t(2) Open exisiting account\n\t(3) Return to Main Window \n\nNumber: ");
			/*taking the desired input into varibale*/
			scanf("%d",&AdminSub);
			
			/*check which subwindow the program would excute*/
			if (AdminSub==CreateNewAccount)
			{
				/*Creating new accout*/
				Accounts[Number_Of_Accounts] = Create_New_Account();
				/*indication when process is done*/
				printf("\n\t\t\t\tAccount no : [%u] is successfuly created\n",++Number_Of_Accounts);
				
			}
			else if (AdminSub==OpenExisitingAccount)
			{
				/*open ExisitingAccount*/
				printf("\n\t\t\twelcome to open exisiting Account");
				
				Bank_Account_index=Open_Exisiting_Account();

				printf("\n\t(1) Make Transaction\n\t\(2) Change Account Status\n\t(3) Get Cash \n\t(4) Deposit in Account \n\nNumber: ");
				scanf("%u",&ExisitingAccount_sub);

				if (ExisitingAccount_sub==MakeTransaction_Admin)
				{
					Make_Transaction();
				}
				else if (ExisitingAccount_sub==ChangeAccountStatus_Admin)
				{
					Change_Account_Status();
				}
				else if (ExisitingAccount_sub==GetCash_Admin)
				{
					GetCash();
				}
				else if (ExisitingAccount_sub==DepositInAccount_Admin)
				{
					Deposit_In_Account();
				}
				else if (ExisitingAccount_sub==ReturnToMainMenu_Admin)
				{
					printf("\nClosing Window\n");
					break;
				}
			}
			else if (AdminSub==ExitAdminWindow)
			{
				printf("\n\t\t Exiting Admin Window\n");
				break;
			}
			else
			{
				printf("\n\t\t you have choose Wrong option please try again\n");
				continue;
			}
		}
	
	}
	/*Client Window*/
	else if (Window==ClientWindow)
	{
		u8 i;
		u8 check=0;
			printf("\nwelcome to client window\n");
			printf("\nplease enter Account ID Number: ");
			scanf("%u",&ID_Number);
			printf("\nplease enter Account Password: ");
			scanf("%u",&Client_Password);
			
			for (i=0;i<Number_Of_Accounts;++i)
			{
				if (Accounts[i].Bank_Account_ID==ID_Number && Accounts[i].Password==Client_Password)
				{
					Bank_Account_index=i;
					check = 1;
					break;
				}
			}
			if (check!=1)
			{
				printf("\nyou've enter invalid ID or password\n");
				break;
			}
		
		while (1)
		{
			printf("\n\t\t(1) Make Transaction\n\t\t(2) Change Account Password\n\t\t(3) Get Cash\n\t\t(4) Deposit In Account\n\t\t(5) Return To Main Menu \nNumber: ");
			scanf("%d",&ClientSub);
			if (ClientSub==MakeTransaction_client)
			{
				Make_Transaction();
			}
			else if (ClientSub==ChangeAccountPassword_client)
			{
				Change_Account_Password_client();
			}
			else if (ClientSub==GetCash_client)
			{
				GetCash();
			}
			else if(ClientSub==DepositInAccount_client)
			{
				Deposit_In_Account();
			}
			else if (ClientSub==ExitClientWindow_client)
			{
				printf("\n\t\t ExitClientWindow\n");
				break;
			}
			else
			{
				printf("\n\t\t you have choose Wrong option please try again\n");
				continue;
			}
		
		
		}
	}
	else if (Window==3)
	{
		printf("Closing Application");
		break;
	}
	else
	{
		printf("\n\t\t you have choose Wrong option please try again\n");
		continue;
	}
	
	}
	
}


Account_S Create_New_Account(void)
{
	/*decleare struct*/
	Account_S Acc;
	printf("\n==================================================\n");
	/*getting inputs from user*/
	printf("please enter full Name: ");
	fflush(stdin);
	scanf("%[^\n]s",Acc.Name);
	fflush(stdin);
	printf("please enter full address: ");
	scanf("%[^\n]s",Acc.Address);
	fflush(stdin);
	printf("please enter National_ID: ");
	scanf("%[^\n]s",Acc.National_ID);
	
	printf("please enter your age: ");
	scanf("%u",&Acc.Age);
	if (Acc.Age>=21)
	{
		fflush(stdin);
		strcpy(Acc.Guardian_National_ID,"None");
	}
	else
	{
		printf("please enter Guardian National ID: ");
		fflush(stdin);
		scanf("%[^\n]s",Acc.Guardian_National_ID);
	}
	printf("please enter Account Balance: ");
	scanf("%d",&Acc.Balance);
	/*set account to active mode*/
	Acc.Account_Status=Active;
	/*generating random Account ID and password*/
    srand(time(0));
	Acc.Bank_Account_ID = rand()%(End_ID)+Start_ID;
	srand(time(0));
	Acc.Password = rand()%(End_Password)+Start_Password;
	
	/*giving user the automatated info password and Bank ID aslo indicates successufly process*/
	printf("\n\t \t=============================================================================\n \t \t Bank ID of name [%s] is [%u] Password Is [%u]\n\t \t=============================================================================\n",Acc.Name,Acc.Bank_Account_ID,Acc.Password);
	/*returning the struct*/
	return Acc;
}

u32 Open_Exisiting_Account(void)
{
	/*decleare variables counter and ID_Number*/
	u8 i;
	u32 ID_Number;
	/*gettig Bank ID number from admin user*/
	printf("\nplease enter Account ID Number: ");
	scanf("%u",&ID_Number);
	
	for (i=0;i<Number_Of_Accounts;++i)
	{
		if (Accounts[i].Bank_Account_ID==ID_Number)
		{
			return i;
		}
	}
	printf("\nID doesn't exist please try again\n");
	printf("\t(1) Main window \n\t(2) Try again: \n");
	printf("\nNumber: ");
		scanf("%d",&Window);
		fflush(stdin);
		if(Window == 1)
		{
			printf("\n");
			system("cls");
			main();
		}
		else
		{
			Open_Exisiting_Account();
		}
	
}

void Make_Transaction(void)
{
	printf("\n Data Related to Tranfer Account ");
	u8 Transfer_Bank_Account_index=Open_Exisiting_Account();
	u32 Money_Transfer;
	printf("Please enter amount of money to be transfered: ");
	scanf("%u",&Money_Transfer);
	
	if (Accounts[Bank_Account_index].Balance<Money_Transfer)
	{
		printf("\n sorry your current balance isn\'t suffcient");
	}
	else if (Accounts[Bank_Account_index].Balance>=Money_Transfer && Accounts[Bank_Account_index].Account_Status==Active && Accounts[Transfer_Bank_Account_index].Account_Status==Active)
	{
		Accounts[Bank_Account_index].Balance-=Money_Transfer;
		Accounts[Transfer_Bank_Account_index].Balance+=Money_Transfer;
		printf("\nyou have been transfered %u successufly your balance is: %u",Money_Transfer,Accounts[Bank_Account_index].Balance);
	}
}

void Change_Account_Status(void)
{
	u8 State;
	
	while(1)
	{
	printf("\nChange your account state to: \n 1) Active 2)Restricted 3)Closed\n\t\t Number: ");
	scanf("%u",&State);
	
	if (State==1 || State==2 || State==3)
	{
		Accounts[Bank_Account_index].Account_Status=State;
		printf("Done!\n");
		break;
	}	
	else
		printf("\nyou have entered invalid number\n");
	}
}

void GetCash(void)
{
	u32 Amount_Of_Money;
	printf("\nplease enter amount of Money: ");
	scanf("%u",&Amount_Of_Money);
	if (Accounts[Bank_Account_index].Balance>=Amount_Of_Money)
	{
		Accounts[Bank_Account_index].Balance-=Amount_Of_Money;
		printf("\nsuccessful operation done get out %u\n your balance is: %u",Amount_Of_Money,Accounts[Bank_Account_index].Balance);
	}
	else
	{
		printf("\nSorry Insuffcient Balance");
	}
}
void Deposit_In_Account(void)
{
	u32 Added_Money;
	printf("Please Enter Amount of Money to be added: ");
	scanf("%u",&Added_Money);
	Accounts[Bank_Account_index].Balance+=Added_Money;
	printf("\nsuccessful operation done your balance is: %u",Accounts[Bank_Account_index].Balance);
}

void Change_Account_Password_client(void)
{
	printf("Please enter old Password : ");
	scanf("%u",&Client_Password);
	printf("old password is: %u\n", Client_Password);
	printf("Please enter New Password 4 digits: ");
	scanf("%u",&New_Password);
	printf("New password is: %u", New_Password);
	if ( Client_Password == Accounts[Bank_Account_index].Password)
	{
		Accounts[Bank_Account_index].Password = New_Password;
		printf("\noperation is Done! your new password %u\n",Accounts[Bank_Account_index].Password);
	}
	else if (Client_Password != (Accounts[Bank_Account_index].Password))
	{
		printf("\nSorry you've enter wrong Password");
	}
}

int USER_PASS_CHECK(char a[],char b[])  
{  
    int flag=0,i=0;
    while(a[i]!='\0' || b[i]!='\0')
    {  
       if(a[i]!=b[i])  
       {  
           flag=1;  
           break;  
       }  
       i++;  
    }  
    if(flag==0)  
    return RETURN_OK;  
    else  
    return RETURN_NOK;  
}