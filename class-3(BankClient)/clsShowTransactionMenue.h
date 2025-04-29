#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsDepositScreen.h"
#include"clsWidthdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTranformationScreen.h"
#include"clsTransferLogScreen.h"

class clsShowTransactionMenue: protected clsScreen
{
private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3,eTranform= 4, eRegisterLog = 5, eShowMainMenue  =  6
    
    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositeScreen();
        //cout << "\n Deposit Screen will be here.\n";
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
        //cout << "\n Withdraw Screen will be here.\n";
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalances::ShowTotalBalances();
        //cout << "\n Balances Screen will be here.\n";
    }


    static void _ShowTranformationScreen()
    {
        clsTranformationScreen::ShowTransformationScreen();
        //cout << "\n Balances Screen will be here.\n";
    }


    static void _ShowRegisterLogScreen()
    {
        clsTransferLogScreen::ShowTransferLog();
        //clsTranformationScreen::ShowTransformationScreen();
        //cout << "\n Balances Screen will be here.\n";
    }
    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }


    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eTranform:
        {
            system("cls");
            _ShowTranformationScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eRegisterLog:
        {
            system("cls");
            _ShowRegisterLogScreen();    
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }

public:
    static void ShowTransactionsMenue()
    {

        if (!CheckAccessRight(clsUser::enPermissions::pTranactions)) {
            return; // this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Tranform.\n";
        cout << setw(37) << left << "" << "\t[5] Register Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions) ReadTransactionsMenueOption());
    }

};

