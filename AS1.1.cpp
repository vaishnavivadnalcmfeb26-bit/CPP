#include<iostream>
using namespace std;

// Global variables
string name;
int roll;
float marks;
char grade;

// Accept information
void accept()
{
    cout<<"Enter Name: ";
    cin>>name;

    cout<<"Enter Roll Number: ";
    cin>>roll;

    cout<<"Enter Marks: ";
    cin>>marks;
}

// Calculate grade
void gradeCal()
{
    if(marks>=90) grade='A';
    else if(marks>=80) grade='B';
    else if(marks>=70) grade='C';
    else if(marks>=60) grade='D';
    else grade='F';
}

// Display information
void display()
{
    cout<<"\nName: "<<name;
    cout<<"\nRoll No: "<<roll;
    cout<<"\nMarks: "<<marks;
    cout<<"\nGrade: "<<grade<<endl;
}

int main()
{
    int ch;

    do
    {
        cout<<"\n1.Accept\n2.Display\n3.Calculate Grade\n4.Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        if(ch==1)
            accept();
        else if(ch==2)
            display();
        else if(ch==3)
            gradeCal();
        else if(ch==4)
            cout<<"Exit";

    }while(ch!=4);

    return 0;
}