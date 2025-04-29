#pragma once
#include"clsInputValidate.h"
#include<iomanip>
#include"clsScreen.h"
#include"clsListCurrencies.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculator.h"
class clsCurrenciesScreen : protected clsScreen
{


	enum enCurrenciesMainMenue{eShowListCurrencies = 1 , eFindCurrency  =2 ,eUpdateCurrency= 3 ,eCurrencyCalculator = 4 , eExitMenue = 5};


	static short ReadCurrencyMenueOption() {
		cout << setw(37) << left << " " << "Choose what do you want to do? [1 to 6]? ";
		short choice = clsInputValidate<int>::ReadNumberBetween(1, 5, "Enter Number between 1 to 6? ");
		return choice;

	}


	static void _GoBackToCurrencyUsersMenue()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system("pause>0");
		ShowCurrencyMenue();
	}


	static void  _ShowListCurrenciesScreen() {
		//cout << "show currency list";
		clsListCurrencies::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen() {

		clsFindCurrenciesScreen::ShowFindScreen();
	}

	static void _ShowUpdateCurrencyScreen() {
		clsUpdateCurrencyScreen::ShowUpdateScreen();
	}

	static void _ShowCurrencyCalculator() {
		clsCurrencyCalculator::ShowCureencyCalculatorScreen();
	}


	static void  _ShowExit() {

	}


	static void _PerformCurrencyMenue(enCurrenciesMainMenue CurrencyMenueOption) {
		switch (CurrencyMenueOption)
		{
		case enCurrenciesMainMenue::eShowListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyUsersMenue();
			break;

		case enCurrenciesMainMenue::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyUsersMenue();
			break;

		case enCurrenciesMainMenue::eUpdateCurrency:
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrencyUsersMenue();
			break;

		
		case enCurrenciesMainMenue::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackToCurrencyUsersMenue();
			break;



		default:
			break;
		}
	}


public:

	static void ShowCurrencyMenue() {


		system("cls");
		_DrawScreenHeader("\t Currency Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Currency List.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency .\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate .\n";
		cout << setw(37) << left << "" << "\t[4] Currency Claclator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";



		_PerformCurrencyMenue((enCurrenciesMainMenue)ReadCurrencyMenueOption());

	}
	

};

