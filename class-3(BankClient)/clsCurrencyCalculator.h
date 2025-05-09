#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsString.h"
class clsCurrencyCalculator : protected clsScreen
{

private:
	
	static void _PrintCurrencyCard(clsCurrency Currency ,string Title = "currency Card: ") {

		cout << "\n" << Title << "\n";
		cout << "\n___________________\n";
		cout << "\Country: " << Currency.Country();
		cout << "\nCode   : " << Currency.CurrencyCode();
		cout << "\nName  : " << Currency.CurrencyName();
		cout << "\nRate  : " << Currency.Rate();
		cout << "\n___________________\n";
	}

	static string  _ReadCurrencyCode() {
		string CurrencyFrom = clsInputValidate<string>::ReadString();

		return CurrencyFrom;
	}

	static clsCurrency _GetCurrency(string Message) {
		
		string CurrencyCode;
		cout << Message << endl;
		CurrencyCode = clsInputValidate<string>::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "\nCurrency Is not Found , write a right currency Code? ";
			CurrencyCode = clsInputValidate<string>::ReadString();
		
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;

	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2) {

		_PrintCurrencyCard(Currency1, "Currency From");
		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD") {
			return;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrrency2 = Currency1.convertToOtherCurrency(Amount, Currency2);
		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

	}


	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange : ";
		float NewRate = 0;

		NewRate = clsInputValidate<float>::ReadNumber();
		return NewRate;
	}



public:

	static	void ShowCureencyCalculatorScreen() {
		
		char Continue = 'y';
		while (Continue == 'y' || Continue == 'Y') {
			system("cls");

			_DrawScreenHeader("\t Currency Calculator screen");


			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();
			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);
			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Continue;

		}
	}








};

