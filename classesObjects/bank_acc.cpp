#include <iostream>
#include <string>
using namespace std;

class account{
string holder_name;
string acc_no;
string acc_type;
double balance;
public:
    void initialize();
    void deposit(double);
    void withdraw(double);
    void display();
};

void account::initialize(){
cout<<"enter the account holder name"<<endl;
cin>>holder_name;
cout<<"enter account number"<<endl;
cin>>acc_no;
cout<<"enter account type"<<endl;
cin>>acc_type;
cout<<"enter account balance"<<endl;
cin>>balance;
}

void account::deposit(double amt){
balance=balance+amt;
}

void account::withdraw(double amt){
    if(amt>balance)
        cout<<"Insufficient balance"<<endl;
    else
balance-=amt;
}

void account::display(){
cout<<"Account holder name:"<<holder_name<<endl;
cout<<"Current Balance: Rs."<<balance<<endl;
}

main(){
account acc;
double amt;
acc.initialize();
int choice;

do{
cout<<"Choose one of the following:"<<endl<<
        "1.Deposit amount"<<endl<<
        "2.Withdraw amount"<<endl<<
        "3.Display balance"<<endl<<
        "4.Exit"<<endl;
cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter amount to be deposited: ";
        cin>>amt;
        acc.deposit(amt);
        acc.display();
        break;
        case 2:
        cout<<"Enter amount to be withdrawn: ";
        cin>>amt;
        acc.withdraw(amt);
        acc.display();
        break;
        case 3:
        acc.display();
        break;
        case 4:
        break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }while(choice!=4);

}
