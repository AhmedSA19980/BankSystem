#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsBankClient.h"
#include"Global.h";



class clsTranformationScreen : protected clsScreen
{

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
       
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }



	//intructor 

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::IsClientExsit(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}
		return AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate<float>::ReadNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate<double>::ReadNumber();
		}
		return Amount;
	}




public:


	
	static void  ShowTransformationScreen() {

		/*_DrawScreenHeader("\t\tTranform Screen !");

		cout << "\n Enter an account Number to trafer from?";
		string From = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExsit(From)) {
			cout << "\nAccount Nummber is Not found,enter a right account number !\n";
			From = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(From);
		_PrintClient(Client);


		cout << "\n Enter an account Number to tranfer to ?";
		string To = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExsit(To)) {
			cout << "\nAccount Nummber is Not found ,enter a right account number !\n";
			From = clsInputValidate::ReadString();
		}



		clsBankClient Client2 = clsBankClient::Find(To);
		_PrintClient(Client2);


		double Amount = 0;
		cout << "\nPlease enter amount of money to transfer ? ";
		Amount = clsInputValidate::ReadDblNumber();

		while (!Client.Withdraw(Amount) ){
			cout << "\nAmount is exceeding the availabe balance,";
			cout << "\nenter another amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		cout << "\nAre you sure you want to perform this transaction n/y?";
		char Answer = 'n';
		cin >>Answer;

		if (Answer == 'y' || Answer == 'Y') {

			if (Client.Withdraw(Amount)) {
				Client2.Deposit(Amount);

				cout << "\n\n Tranfer Done Succesfully !\n";
				_PrintClient(Client);
				_PrintClient(Client2);
			}
		}
		else {
			cout << "\nCancel Operation\n!";
		}
	}*/


		
		
		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(DestinationClient);

		float Amount = ReadAmount(SourceClient);


		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName ))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);


	}

	static void AddTransferDataLog() {

	}

};

