#pragma once
#include<string>
#include"clsBankClient.h";
#include"clsInputValidate.h";
#include"clsScreen.h";


using namespace std;

class clsAddNewClientScreen :protected clsScreen
{

private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate<string>::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate<string>::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate<string>::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate<string>::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate<string>::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate<float>::ReadNumber();
    }

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


public:
    static void ShowAddNewClient() {
        if (!CheckAccessRight(clsUser::enPermissions::pAddNewClient)) {
            return; // this will exit the function and it will not continue
        }
        string AccountNumber = "";

        _DrawScreenHeader("\t Add new Client Screen");// iheritance method

        cout << "\nplease Enter client Account number: ";
        AccountNumber = clsInputValidate<string>::ReadString();
        while (clsBankClient::IsClientExsit(AccountNumber)) {
            cout << "\nAccount number is already exist, choose another one: ";
            AccountNumber = clsInputValidate<string>::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();


        switch (SaveResult)
        {

        case clsBankClient::svSucceeded:
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(NewClient);
            break;

        case clsBankClient::svFaildEmptyObject:
            cout << "\nError account was not saved because it's Empty";
            break;

        case clsBankClient::svFailedAccountNumberExist:
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
    }
};

