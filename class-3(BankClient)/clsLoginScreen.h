#pragma once
#include"clsScreen.h"
#include"Global.h"
#include "clsMainScreen.h"
#include<fstream>


using namespace std;

class clsLoginScreen : protected clsScreen
{


private:
	
	static bool _Login() {
		bool LoginFailed = false;
		string Username, password;
		short LoginTimes = 0;

		do
		{
			if (LoginFailed ) {
				LoginTimes++;
				cout << "\nInvalid username and password\n";
				cout << "\nyou have" << (3 - LoginTimes) << "Trial(s) Login\n\n.";

				
			}
			if (LoginTimes == 3) {
				cout << "\nyou have Done 3 attemps !";
				return false;
			}
		
	
			cout << "\nEnter  user name:";
			cin >> Username;

			cout << "\nEnter password:";
			cin >> password;


			CurrentUser = clsUser::Find(Username, password); // cureent is global variable that the system will load it's entire classes
			LoginFailed = CurrentUser.IsEmpty(); // check if object is empty than login failed (password== user.passwod ,username == user.username)

		
		

		} while (LoginFailed);

		CurrentUser.LoginRegister();

		clsMainScreen::ShowMainMenue();
		
		return true;


	}


public:
	static bool  ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t Login screen");
		return 	_Login();
	}
};

