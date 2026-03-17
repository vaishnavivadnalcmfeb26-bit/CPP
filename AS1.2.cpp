#include<iostream>
using namespace std;

class BankAccount
{
private:
    int accNo;
    string name;
    float balance;

public:

    // accept account details
    void setData()
    {
        cout<<"Enter Account Number: ";
        cin>>accNo;

        cout<<"Enter Name: ";
        cin>>name;

        cout<<"Enter Balance: ";
        cin>>balance;
    }

    // deposit money
    void deposit()
    {
        float amt;
        cout<<"Enter amount to deposit: ";
        cin>>amt;

        balance = balance + amt;
    }

    // withdraw money
    void withdraw()
    {
        float amt;
        cout<<"Enter amount to withdraw: ";
        cin>>amt;

        if(amt <= balance)
            balance = balance - amt;
        else
            cout<<"Insufficient Balance";
    }

    // display details
    void display()
    {
        cout<<"\nAccount No: "<<accNo;
        cout<<"\nName: "<<name;
        cout<<"\nBalance: "<<balance<<endl;
    }
};

int main()
{
    BankAccount b;
    int ch;

    b.setData(); // take details once

    do
    {
        cout<<"\n1.Deposit\n2.Withdraw\n3.Display\n4.Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        if(ch==1)
            b.deposit();
        else if(ch==2)
            b.withdraw();
        else if(ch==3)
            b.display();

    }while(ch!=4);

    return 0;
}