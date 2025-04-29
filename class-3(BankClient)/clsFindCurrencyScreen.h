#pragma once
#include "clsscreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
class clsFindCurrenciesScreen :protected clsScreen
{

	enum enCurrencyChoice{eCode  =1 , eCountry};

	static short _ReadChoice() {
		 short choice = clsInputValidate<int>::ReadNumberBetween(1, 2, "Find By Code[1] or Country[2] ?  ");
		return choice;

	}


	static void _PrintCurrencyCard(clsCurrency Currency) {

        cout << "\nUser Card:";
        cout << "\n___________________\n";
        cout << "\Country: " << Currency.Country();
        cout << "\nCode   : " << Currency.CurrencyCode()  ;
        cout << "\nName  : " << Currency.CurrencyName();
        cout << "\nRate  : " << Currency.Rate();
        cout << "\n___________________\n";
	}


	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}
	

public:

	static void ShowFindScreen() {

		_DrawScreenHeader("\t  Find Currency Screen");
		cout << "Find By Code[1] or Country[2] ?";
		short choice = (enCurrencyChoice)_ReadChoice();
		string Code;
	//	clsCurrency c = clsCurrency::FindByCode(Code);
		if (choice == enCurrencyChoice::eCode) {
			cout << "enter a Code: ?" ;
			Code = clsInputValidate<string>::ReadString();
			clsCurrency c = clsCurrency::FindByCode(Code);
			_ShowResults(c);
		}else if (choice == enCurrencyChoice::eCountry) {
			cout << "enter a Country: ?";

			Code = clsInputValidate<string>::ReadString();
			clsCurrency c = clsCurrency::FindByCountry(Code);
			_ShowResults(c);

		}
		

	}

};

