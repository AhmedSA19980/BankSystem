#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"



class clsUpdateCurrencyScreen :protected clsScreen
{
  

    static void _PrintCurrencyCard(clsCurrency Currency) {

        cout << "\nUser Card:";
        cout << "\n___________________\n";
        cout << "\Country: " << Currency.Country();
        cout << "\nCode   : " << Currency.CurrencyCode();
        cout << "\nName  : " << Currency.CurrencyName();
        cout << "\nRate  : " << Currency.Rate();
        cout << "\n___________________\n";
    }

    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;

        NewRate = clsInputValidate<float>::ReadNumber();
        return NewRate;
    }

   


public:

    static void ShowUpdateScreen() {
        _DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode = "";

        cout << "Please, enter Currency Code: ";
        CurrencyCode =  clsInputValidate<string>::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate<string>::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrencyCard(Currency);

        cout << "Are Sure you want to update Rate of this currency y/n? ";
        char Answer = 'n';
        cin >> Answer;

   
        if (Answer == 'y' || Answer == 'Y') {

            cout << "\n\nUpdate Currency Rate";
            cout << "\n--------------------\n";
            cout << "enter a new Rate: ";
     

            Currency.UpdateRate(_ReadRate());
            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrencyCard(Currency);


        }

    }

};

