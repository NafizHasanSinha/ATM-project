#include<bits/stdc++.h>

using namespace std;

struct node
{
    long long int cardNo;
    int pin;
    string name;
    int cash;
    node *next;
    node *prev;
};

class ATM
{
    node *head;
    string x;
    long long int y;
    int z;
    int c;

public:
    ATM()
    {
        head = NULL;
        x = "";
        y = 0;
        z = 0;
        c = 0;
    }
    int count_digits(long long int n)
    {

        string num = to_string(n);
        return num.size();
    }
    void Account()
    {

        if (head == NULL)
        {
            node *newnode = new node;
            cout << "Please enter your name: ";
            cin >> x;
            newnode->name = x;

            cout << "Please enter your Card No: ";
            cin >> y;
            while(count_digits(y) < 11 || count_digits(y) > 11)
            {
                cout<<"Put 11 digits cardNo: ";
                cin>>y;
            }
            newnode->cardNo = y;

            cout << "Please enter your Pin: ";
            cin >> z;
            while(count_digits(z) < 4 || count_digits(z) > 4)
            {
                cout<<"Put 4 digits pin: ";
                cin>>z;
            }
            newnode->pin = z;

            newnode->cash = 0;

            newnode->next = NULL;
            newnode->prev = NULL;
            head = newnode;

            cout << "Your Account Created" << endl;
        }
        else
        {
            node*newnode=new node;
            cout<<"Please Enter your name: ";
            cin>>x;
            newnode->name=x;

            cout<<"Please enter your Card No: ";
            cin>>y;
            while(count_digits(y) < 11 || count_digits(y) > 11)
            {
                cout<<"Put 11 digits cardNo: ";
                cin>>y;
            }
            newnode->cardNo=y;

            cout<<"Please enter your Pin: ";
            cin>>z;
            while(count_digits(z) < 4 || count_digits(z) > 4)
            {
                cout<<"Put 4 digits pin: ";
                cin>>z;
            }
            newnode->pin=z;

            newnode->cash=0;

            newnode->next=NULL;
            node*temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            cout<<"Your Account created"<<endl;
        }
    }

    int LoginAccount()
    {
        node *temp = head;
        cout << "Please enter your Card No: ";
        cin >> y;

        cout << "Please enter your Pin: ";
        cin >> z;
        while (temp != NULL)
        {
            if (temp->cardNo == y && temp->pin == z)
            {
                cout << "*****************************************" << endl;
                cout << "Enter Name: " << temp->name << endl;
                return 0;
            }
            temp = temp->next;
        }

        cout << "Your cardNo or Pin is wrong\n";
        cout << "Please Try Again....\n\n";
        return 1;
    }

    void Deposit()
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->cardNo == y && temp->pin == z)
            {
                cout << "Please Enter The Amount: ";
                cin >> c;
                temp->cash = temp->cash + c;
                cout << "Amount successfully Added" << endl;
                break;
            }
            temp = temp->next;
        }
    }
    void widthdraw()
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->cardNo == y && temp->pin == z)
            {
                cout << "Please Enter The Amount: ";
                cin >> c;
                if (temp->cash >= c)
                {
                    temp->cash = temp->cash - c;
                    cout << "Amount successfully Withdrawn" << endl;
                }
                else
                {
                    cout << "You don't have enough Balance to withdraw" << endl;
                    cout << "************" << endl;
                }
                break;
            }
            temp = temp->next;
        }
    }
    void Balance_check()
    {
        node*temp=head;
        while(temp!=NULL)
        {
            if(temp->cardNo==y&&temp->pin==z)
            {
                cout<<"Your Balance is: "<<temp->cash<<".TK"<<endl;
                break;
            }
            temp=temp->next;
        }
    }
    void user_menu()
    {
        cout << "_____________________" << endl;
        cout << "       USER MENU" << endl;
        cout << " 1. Deposit Money" << endl;
        cout << " 2. Withdraw Money" << endl;
        cout << " 3. Check Balance" << endl;
        cout << " 4. Main Menu" << endl;
        cout << "_____________________" << endl;

        int command;

        cout << "Enter the command: ";
        cin >> command;

        switch(command)
        {
        case 1:
            Deposit();
            user_menu();
            break;
        case 2:
            widthdraw();
            user_menu();
            break;
        case 3:
            Balance_check();
            user_menu();
            break;
        case 4:
            main_menu();
            break;
        default:
            cout << "Wrong  input" << endl;
            cout << "Please Try Again...."<<endl << endl;
            return user_menu();
        }
    }
    void main_menu()
    {
        cout << "|___________________|" << endl;
        cout << "|    MAIN MENU      |" << endl;
        cout << "|1. Create Account  |" << endl;
        cout << "|2. Login to Account|" << endl;
        cout << "|3. Exit            |" << endl;
        cout << "|___________________|" << endl;
        int scommand;

        cout << "Enter the command: ";
        cin >> scommand;

        switch (scommand)
        {
        case 1:
            Account();
            main_menu();
            break;
        case 2:
            if (LoginAccount() == 0)
                user_menu();
            else
                main_menu();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout<<endl << "Wrong input" << endl;
            cout << "Please Try Again...."<<endl << endl;
            return main_menu();
        }
    }
};



int main()
{
    cout << "**********************************" << endl;
    cout << "*   Welcome To The MY ATM Bank   *" << endl;
    cout << "**********************************"<< endl;

    ATM obj;
    obj.main_menu();
    return 0;
}
