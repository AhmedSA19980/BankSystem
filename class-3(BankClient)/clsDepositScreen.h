#pragma once
#include"clsScreen.h";
#include"clsBankClient.h";
using namespace std;
class clsDepositScreen :protected clsScreen
{

private:

    static void  _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
    static string _ReadAccountNumber() {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    };



public:
    static void ShowDepositeScreen(){
        _DrawScreenHeader("\tShowDepositScreen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExsit(AccountNumber)) {
            cout << "\nClient With [" << AccountNumber << "] ,Does not Exist !";
            string AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);


        double Amount = 0;
        cout << "\npls, enter the amount of money to deposit ? ";
        Amount = clsInputValidate<double>::ReadNumber();

        cout << "\nAre you sure you want to perform this transaction y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            Client1.Deposit(Amount);
            cout << "\nAmount of Money Deposited succesfully";
            cout << "\nNew Balances is: " << Client1.AccountBalance << endl;
        }
        else {
            cout << "\nOperation was Cancelled!";
        }
    
    }

};

