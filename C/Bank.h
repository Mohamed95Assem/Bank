//Bank.h

#ifndef _BANK_H
#define _BANK_H

#include "STD_TYPES.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define AdminWindow 1
#define ClientWindow 2

#define CreateNewAccount 1
#define OpenExisitingAccount 2
#define ExitAdminWindow 3

#define MakeTransaction_Admin 1
#define ChangeAccountStatus_Admin 2
#define GetCash_Admin 3
#define DepositInAccount_Admin 4
#define ReturnToMainMenu_Admin 5

#define MakeTransaction_client 1
#define ChangeAccountPassword_client 2
#define GetCash_client 3
#define DepositInAccount_client 4
#define ExitClientWindow_client 5


#define Active 1
#define Restricted 2
#define Closed 3

#define Start_ID 1000
#define End_ID 9999

#define Start_Password 100000
#define End_Password 999999

#define AdminUser "Admin"
#define AdminPass "Admin"

typedef struct
{
	u8 Age;
	u8 Account_Status;
	u16 Password;
	s32 Balance;
	u32 Bank_Account_ID;
	u8 National_ID[15];
	u8 Guardian_National_ID[15];
	u8 Name[60];
	u8 Address[80];
}Account_S;

typedef enum{
	RETURN_NOK,
	RETURN_OK,
}EStatus_t;

/*varibales decleration*/
u8 Window;
u8 Window_flag;
u8 AdminSub;
u8 AdminSSub;
u8 ClientSub;
u8 ExisitingAccount_sub;
u8 Number_Of_Accounts=0;
u16 Client_Password;
u16 New_Password;
u32 ID_Number;
u32 Random_Number;
u8 Admin_Username[5];
u8 Admi_Password[5];
Account_S Accounts[100]={};
u8 Bank_Account_index;

/*functions decleration*/
Account_S Create_New_Account(void);
u32 Open_Exisiting_Account(void);
void Make_Transaction(void);
void Change_Account_Status(void);
void GetCash(void);
void Deposit_In_Account(void);
void Change_Account_Password_client(void);
int USER_PASS_CHECK(char a[],char b[]);

#endif
