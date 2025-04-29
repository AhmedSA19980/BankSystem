#pragma once
#include"clsInputValidate.h";
#include"clsBankClient.h";
#include "clsScreen.h";

using namespace std;


class clsDeleteClientScreen : protected  clsScreen
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

public:

    static void ShowDeleteClient() {

        if (!CheckAccessRight(clsUser::enPermissions::pDeleteClient)) {
            return; // this will exit the function and it will not continue
        }

        // keep in mind you need to del from memory (object) and File, same as update ,add
        _DrawScreenHeader("\t\t  Show Delete Client Screen ");
        string AccountNumber = "";

        cout << "\nplease Enter client Account number: ";
        AccountNumber = clsInputValidate<string>::ReadString();
        while (!clsBankClient::IsClientExsit(AccountNumber)) {
            cout << "\nAccount number is not Found, choose another one: ";
            AccountNumber = clsInputValidate<string>::ReadString();
        }

        clsBankClient DelClient = clsBankClient::Find(AccountNumber);
        _PrintClient(DelClient);

        cout << "\nAre Sure to delete this client y/n ?";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            if (DelClient.Delete()) {
                cout << "\nClient was deleted sucessfuly:-)";
                _PrintClient(DelClient);; // print empty object
            }
            else {
                cout << "\nError Client Was not Deleted!";
            }
        }

    }



};

