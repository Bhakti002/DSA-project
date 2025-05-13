// bank account


#include<iostream>
using namespace std;

int balance = 50000,saving,intrest,pin;
double accountNumber;
    
class Savingaccount
{

	public:
		void intrest()
        {
			cout<<"__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__\n";
			cout<<"\nYour total balance in your account is "<<balance<<endl;
			saving=(3*balance)/100;
			cout<<"Total intrest is : "<<saving<<endl;
			cout<<"Total balance with intrest : "<<saving + balance<<endl;
			cout << "Thank you\n\n"<< endl;
			cout<<"__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__\n";
		}
};
class FixedDepositAccount
{
	public:
		void fixcalculateintrest()
        {
			cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
			cout<<"\nOur bank give intrest 7% and for senior citizen 8%.";
			cout<<"Your active deposits are 4.";
			intrest=(7*balance)/100;
			cout<<"You get total intrest"<<intrest<<"annually in your saving account.";
			cout<<"Total intrest add in your bank account annually.";
			cout << "Thank you\n\n"<< endl;
			cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
		}
};
class BankAccount:public Savingaccount , public FixedDepositAccount{
public:
    void getAccountInfo() 
    {
    	cout<<"********************************* Welcome to my bank *********************************\n";
        cout << "Please enter your account number: ";
        cin >> accountNumber;
        cout << "Please enter your PIN number: ";
        cin >> pin;
    
        // set pin

        if (pin == 2003)
        {
            int choice;
            cout<<"__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__\n";
            cout<<"Account Holder : Bhakti Bhavsar                           Account Number : ****************4242\n";
            cout<<"__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__\n";
            cout << "\nWhich type of service do you need?";
            cout << "\n Deposit press 1";
            cout << "\n Withdraw press 2";
            cout << "\n Check balance press 3";
            cout << "\n Account info press 4";
            cout << "\n Saving account info press 5";
            cout << "\n Fix deposit details press 6";
            cout << "\n\nEnter choice: ";
            cin >> choice;
            cout<<endl;

            switch (choice) 
            {
                case 1:
                    deposit();
                    break;
                case 2:
                    withdraw();
                    break;
                case 3:
                    showBalance();
                    break;
                case 4:
                    accountInfo();
                    break;
                case 5:
				    intrest();
					break; 
				case 6:
				    fixcalculateintrest();
					break;	   
                default:
                    cout << "Invalid choice!";
            }
        } 
        else 
        {
            cout << "Sorry you have entered invalid PIN !!!" << endl;
        }
    }
// deposite money

    void deposit() 
    {
        int amount;
        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "\nEnter amount to deposit: ";
        cin >> amount;
        balance = balance + amount;
        cout << "Now total balance in your account is " << balance << endl;
        cout << "Thank you\n\n"<< endl;
        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    }
// withdraw money

    void withdraw() 
    {
        int amount;
        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "\nEnter amount to withdraw: ";
        cin >> amount;
        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

        if (amount <= balance) 
        {
            if (amount <= 10000) 
            {
                balance = balance - amount;
                cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
                cout << "\nNow total balance in your account is " << balance << endl;
                cout << "Thank you\n" << endl;
                cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
            } 
            else 
            {
            	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
                cout << "You can only withdraw up to 10,000 at one time.\n" << endl;
                cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
            }
        } 
        else 
        {
        	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
            cout << "You don't have that much balance in your account.\n" << endl;
            cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        }
    }
// total balance

    void showBalance() 
    {
    	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "\nYour account balance is " << balance << endl;
        cout<<endl;
        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    }
// all the information of account

    void accountInfo() 
    {
    	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "\nAccount Holder: Bhakti Bhavsar" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout<<endl;
        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    }
};


int main()
{
    BankAccount obj;
    obj.getAccountInfo();
    return 0;
}
