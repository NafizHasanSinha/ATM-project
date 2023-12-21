#include<bits/stdc++.h>

using namespace std;
int accoNumber =1234;
int pin =1111;
int balance =0;
bool login()
{
    int Anumber = -1;
    int Pinnumber=-1;
    bool AccountInv=true;
    bool PinInv=true;

    cout<<"...WELCOME..."<<endl;
    while(AccountInv)
    {
        cout<<"Enter Your Account Number: ";
        cin>>Anumber;

        if(Anumber==accoNumber)
        {
            AccountInv=false;
        }
        else
        {
            cout<<"Invalid account number!"<<endl<<"Please Try again."<<endl;
        }
    }
    while(PinInv)
    {
        cout<<"Enter Yor PIN: ";
        cin>>Pinnumber;

        if(Pinnumber==pin)
        {
            AccountInv=false;
        }
        else
        {
            cout<<"Invalid PIN Number!"<<endl<<"Please Try again."<<endl;
        }
    }
    return true;
}
int main()
{
    login();
}
