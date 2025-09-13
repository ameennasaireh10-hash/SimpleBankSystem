#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <iomanip>

using namespace std;

class Account
{
    private:
        int AccN = 0 ;
        string name = "None" ;
        double balance = 0 ;
    
    public:
        Account(int A , string n , double b)
        {
            AccN = A ;
            name = n ;
            balance = b ;
        }

        ~Account()
        {

        }

        void deposit(double b) 
        {
            balance += b ;

            cout<<"Your balance after depostie is "<<balance<<endl ;
        }

        void withdraw(double b)
        {
            balance -= b ;

            cout<<"Your balance after withdraw is "<<balance<<endl ;
        } 

        void displayInfo()
        {
            cout<<"Name : "<<name<<endl ;
            cout<<"Account Number : "<<AccN<<endl ;
            cout<<"Balance : "<<balance<<endl ;   
        }

        int getAccountN()
        {
            return AccN;
        }

        string getName()
        {
            return name;
        }

        
};

class BankSystem 
{

    private:
        vector<Account> accounts ;
        int accountCount ;

   public:
        BankSystem() 
        {
            accountCount = 0 ;
            cout<<"Welcome To The Bank System..."<<endl ;
            cout<<"You Can Create An Account, Deposit, Withdraw, Search, Print All Accounts And Delete An Account..."<<endl ;
        }

        ~BankSystem()
        {

        }

        void addAcc(int A , string N , double B)
        {
            Account newAcc(A , N , B) ;

            accounts.push_back(newAcc) ;
        }

        void depositToAcc(int A , double B)
        {
            for(auto& acc : accounts)
            {
                if (acc.getAccountN() == A)
                {
                    acc.deposit(B) ;
                }
            }
        }

        void withdrawFromAcc(int A , double B)
        {
            for(auto& acc : accounts)
            {
                if (acc.getAccountN() == A)
                {
                    acc.withdraw(B) ;
                }
            }
        }

        void SearchAcc(int A) 
        {   
             for(auto& acc : accounts)
            {
                if (acc.getAccountN() == A)
                {
                    cout<<"Account Exists..."<<endl ;
                    acc.displayInfo() ;
                    return;
                }
            }

            cout<<"Unidentified Account"<<endl ;
        }

        void printAllAcc()
        {
            int i = 1 ;
            for(auto& acc : accounts)
            {
                cout<<"#"<<i<<" "<<acc.getAccountN()<<" --> "<<acc.getName()<<endl ;
                i += 1 ;
            }
        }

        void deleteAcc(int A)
        {
            for(int i = 0 ; i < accounts.size() ; i++)
            {
                if (accounts[i].getAccountN() == A)
                {
                    accounts.erase(accounts.begin() + i) ;

                    cout<<"Account "<<A<<" Deleted Successfully...!"<<endl ;

                    return;
                }
            }

            cout<<"Account not found !"<<endl ;
        }
        

};


int main()
{
    BankSystem BankAcc ;
    string command ;

    int id ;
    string name ; 
    double amount ;

    cout<<"You Can Enter Any Command To Start Using The Bank System..."<<endl ;

    bool lcv = true ;

    while (lcv)
    {
        cout<<"Enter Command : ";
        cin>>command ;

        if (command == "create")
        {
            cout<<"Enter Account ID : ";
            cin>>id ;
            cout<<"Enter Account Name : ";
            cin>>name ;
            
            for (size_t i = 1 ; i < name.length() ; ++i) 
            {
                name[i] = tolower(name[i]) ; 
            }
            cout<<"Enter Initial Balance : ";
            cin>>amount ;

            BankAcc.addAcc(id , name , amount) ;
        }
        else if (command == "deposit")
        {
            cout<<"Enter Account ID : ";
            cin>>id ;
            cout<<"Enter Amount To Deposit : ";
            cin>>amount ;

            BankAcc.depositToAcc(id , amount) ;
        }
        else if (command == "withdraw")
        {
            cout<<"Enter Account ID : ";
            cin>>id ;
            cout<<"Enter Amount To Withdraw : ";
            cin>>amount ;

            BankAcc.withdrawFromAcc(id , amount) ;
        }
        else if (command == "search")
        {
            cout<<"Enter Account ID : ";
            cin>>id ;

            BankAcc.SearchAcc(id) ;
        }
        else if (command == "print")
        {
            BankAcc.printAllAcc() ;
        }
        else if (command == "delete")
        {
            cout<<"Enter Account ID : ";
            cin>>id ;

            BankAcc.deleteAcc(id) ;
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            cout<<"Invalid Command! Please Try Again..."<<endl ;
            lcv = false ;
        }
    }

    return 0;
}