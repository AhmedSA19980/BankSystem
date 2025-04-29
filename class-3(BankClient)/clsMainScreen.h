#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsClientListScreen.h";
#include"clsAddNewClientScreen.h";
#include"clsDeleteClientScreen.h";
#include"clsUpdateClientScreen.h";
#include"clsFindClientScreen.h";
#include"clsShowTransactionMenue.h";
#include"clsManageUserScreen.h";
#include"Global.h"
#include"clsRegisterLogscreen.h"
#include "clsCurrencyExchangeMenue.h"


using namespace std;

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister =  8 , eCurrenciesExchangeMenue=  9 , eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate<int>::ReadNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }


    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
        //cout << "\nClient List Screen Will be here...\n";


    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClient();
        
        //cout << "\nAdd New Client Screen Will be here...\n";

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClient();
        //cout << "\nDelete Client Screen Will be here...\n";

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClient();
        //cout << "\nUpdate Client Screen Will be here...\n";

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
        //cout << "\nFind Client Screen Will be here...\n";

    }

    static void _ShowTransactionsMenue()
    {
        clsShowTransactionMenue::ShowTransactionsMenue();
        //cout << "\nTransactions Menue Will be here...\n";

    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
       // cout << "\nUsers Menue Will be here...\n";

    }

    static void _ShowRegisterLogScreen()
    {
        clsRegisterLogscreen::ShowRegisterLogScreen();
        // cout << "\nUsers Menue Will be here...\n";

    }

    static void _ShowCurrencyScreen()
    {
        clsCurrenciesScreen::ShowCurrencyMenue();
       // clsRegisterLogscreen::ShowRegisterLogScreen();
        // cout << "\nUsers Menue Will be here...\n";

    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
        //clsLoginScreen::ShowLoginScreen(); don not run the following line of code it cause circle reference
        // one you login the call stack wait for main screen and then logout ,when login screen run the compiler can't differentiate what stack is done first 
        //cout << "\nEnd Screen Will be here...\n";

    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowRegisterLogScreen();
            _GoBackToMainMenue();
            break;



        case enMainMenueOptions::eCurrenciesExchangeMenue:
            system("cls");
            _ShowCurrencyScreen();
            _GoBackToMainMenue();
            break;


        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            //Login();

            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Menue.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};



