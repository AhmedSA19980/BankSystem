#pragma once
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h";


class clsTransferLogScreen :protected clsScreen
{

    static void PrintLoginRegisterRecordLine(clsBankClient::stTranferLogRecord TransferLoginRegisterRecord) {
        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLoginRegisterRecord.Date;
        cout << "| " << setw(8) << left << TransferLoginRegisterRecord.AccountNumber;
        cout << "| " << setw(8) << left << TransferLoginRegisterRecord.DistinedAccountnumber;
        cout << "| " << setw(8) << left << TransferLoginRegisterRecord.Amount;
        cout << "| " << setw(12) << left << TransferLoginRegisterRecord.AccountBalance;
        cout << "| " << setw(12) << left << TransferLoginRegisterRecord.DistinedAccountBalance;
        cout << "| " << setw(7) << left << TransferLoginRegisterRecord.UserName;

    }







public:

    static void ShowTransferLog() {
        vector <clsBankClient::stTranferLogRecord> vTransferLogclient = clsBankClient::GetTransferLogList();
        string Title = "\t   TransferLog List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogclient.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date";
        cout << "| " << left << setw(8) << "s.ACN";
        cout << "| " << left << setw(8) << "D.ACN";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(12) << "s.accountBalance";
        cout << "| " << left << setw(12) << "d.accountBalance";
        cout << "| " << left << setw(7) << "UserName";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogclient.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient::stTranferLogRecord client : vTransferLogclient)
            {

                PrintLoginRegisterRecordLine(client);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }

};

