#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int Window;
int Window_flag;

class bank
{
    char name[100],add[100],y;
    int balance, amount;
public:
    void open_account ();
    void deposite_money();
    void withdraw_money ();
    void display_account();
};
void bank::open_account()
{
    system("cls");
    cout<<"Enter your full name ::";
    cin.ignore();
    cin.getline(name,100);
    cout<<"Enter your addess ::";
    cin.ignore();
    cin.getline(add,100);
    cout<<"what type of account you want to open saving (s) or current (c)";
    cin>>y;
    cout<<"Enter amount for deposite ::";
    cin>>balance;
    cout<<"Your account is created ";

}
void bank::deposite_money()
{
    int a ;
    cout<<"Enter how much money you want to deposit::";
    cin>>a;
    balance+=a;
    cout<<"Your total deposit amount\n";
}
void bank::display_account()
{
    cout<<"Enter the name ::"<<name<<endl;
    cout<<"Enterened your addees ::"<<add<<endl;
    cout<<"Type of account that you open ::"<<y<<endl;
    cout<<"Amount you deposite ::"<<balance<<endl;

}
void bank::withdraw_money()
{
    cout<<"withdeaw ::";
    cout<<"Enter your amount for withdrawing ";
    cin>>amount;
    balance=balance-amount;
    cout<<"Now your total amount is left ::"<<balance;
}

int main()
{
    do
	{
		std::cout << "\t(1) Admin window :";
		std::cin >> Window;
		if(Window == 1)
		{
			Window_flag = 1 ;
		}
		else
		{
			std::cout << "\n\t\t\t you have choose Wrong option please try again\n\n ";
			Window_flag = 0 ;
		}
	}while(Window_flag != 1);
	
	int ch,x,n;
    bank obj;
    system("cls");
    do
    {
    cout<<"01)Creat account \n";
    cout<<"02)Deposit money \n";
    cout<<"03)WithDraw money \n";
    cout<<"04)Display account\n";
    cout<<"05)Exit\n";
    cout<<"Please sir, select the option from above ";
    cin>>ch;

    switch(ch)
    {
        case 1:"01)Open account \n";
        obj.open_account ();
        break;
        case 2:"02)Deposit money \n";
        obj.deposite_money();
        break;
        case 3:"03)WithDraw money \n";
        obj.withdraw_money ();
        break;
        case 4:"04)Display account\n";
        obj.display_account();
        break;
        case 5:
            if(ch==5)
            {
               cout<< "exit";
            }
        default:
            cout<<"This is not exit please try again ";

    }
    cout<<"\n do you want to select next step then please press::y\n";
    cout<<"if you want to exit then please press:: N ";
    x=getch();
    if(x=='n' || x=='N')
    cout<<"exit";
    }
    while (x=='y' || x=='Y');


 getch();
 return 0;




}