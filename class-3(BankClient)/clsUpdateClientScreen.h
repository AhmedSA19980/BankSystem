#pragma once
#include"clsBankClient.h";
#include"clsInputValidate.h";
#include"clsScreen.h";

using namespace std;

class clsUpdateClientScreen : protected clsScreen
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
    static void ShowUpdateClient() {

        if (!CheckAccessRight(clsUser::enPermissions::pUpdateClients)) {
            return; // this will exit the function and it will not continue
        }
        _DrawScreenHeader("\t\t Update client screen");
        string AccountNumber = "";

        cout << "\nplease Enter client Account number: ";
        AccountNumber = clsInputValidate<string>::ReadString();
        while (!clsBankClient::IsClientExsit(AccountNumber)) {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate<string>::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nAre Sure you would like to update this client y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";

            _ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResult; // 2 res comes saved or not

            SaveResult = Client1.Save();

            switch (SaveResult)
            {

            case clsBankClient::svSucceeded:
                cout << "\nAccount Updated Successfully :-)\n";
                _PrintClient(Client1);
                break;

            case clsBankClient::svFaildEmptyObject:
                cout << "\nError account was not saved because it's Empty";
                break;

            }
        }



    }

};

