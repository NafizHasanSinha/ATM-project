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
    void Account()
    {
        cout<<"                 Create Account"<<endl;
        if (head == NULL)
        {
            node *newnode = new node;
            cout << "Please enter your name: ";
            cin >> x;
            newnode->name = x;

            cout << "Please enter your Card No: ";
            cin >> y;
            newnode->cardNo = y;

            cout << "Please enter your Pin: ";
            cin >> z;
            newnode->pin = z;

            newnode->cash = 0;

            newnode->next = NULL;
            newnode->prev = NULL;
            head = newnode;

            cout << "Account Created" << endl;
        }
        else
        {
            node *newnode = new node;
            cout << "Please Enter your name: ";
            cin >> x;
            newnode->name = x;

            cout << "Please enter your Card No: ";
            cin >> y;
            newnode->cardNo = y;

            cout << "Please enter your Pin: ";
            cin >> z;
            newnode->pin = z;

            newnode->cash = 0;

            newnode->next = NULL;
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
            cout << "Your Account created" << endl;
        }
    }

    int LoginAccount()
    {
        cout<<"                 Login Account"<<endl;
        node *temp = head;
        cout << "Please enter your Card No: ";
        cin >> y;

        cout << "Please enter your Pin: ";
        cin >> z;
        while (temp != NULL)
        {
            if (temp->cardNo == y && temp->pin == z)
            {
                cout << "************" << endl;
                cout << "Enter Name: " << temp->name << endl;
                return 0;
            }
            temp = temp->next;
        }
        cout << "Your cardNo or Pin is wrong\n";
        cout << "Please Try Again....\n\n";
        return 1;
    }

};

int main()
{
    ATM obj;
    obj.Account();
    obj.LoginAccount();
}
