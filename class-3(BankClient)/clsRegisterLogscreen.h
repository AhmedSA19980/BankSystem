#pragma once
#include"clsScreen.h"
#include"clsRegisterLogscreen.h"
#include<iomanip>
#include"clsUser.h";
#include"clsDate.h"
#include<fstream>

class clsRegisterLogscreen : protected clsScreen
{

 


    static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord) {
        cout << setw(8) << left << "" << "| " << setw(15) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(12) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Permissions;

    }

public:





	static void  ShowRegisterLogScreen() {
        if (!CheckAccessRight(clsUser::enPermissions::pLoginRegister)) {
            return; // this will exit the function and it will not continue
        }

        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();
      ;

		string Title = "\t   User List Screen";
		string SubTitle = "\t    (" + to_string(vLoginRegisterRecord.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "| " << left << setw(15) << "Date";
        
        cout << "| " << left << setw(12) << "User Name";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Perrmission";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord  LoginRegisterRecord : vLoginRegisterRecord)
            {

                PrintLoginRegisterRecordLine(LoginRegisterRecord);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

	}

};

