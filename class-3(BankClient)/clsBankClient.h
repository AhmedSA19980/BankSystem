#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include"clsDate.h"
using namespace std;



class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2 };
   
    enMode _Mode;

   
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkClientForDeleted = false; // add new data members for deletion


    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }



    static vector <clsBankClient>  _LoadDataFromFile() {
        vector<clsBankClient> vClients;

        fstream MyFile;

        MyFile.open("clients.txt", ios::in);

        if (MyFile.is_open()) {
            string line;

            while (getline(MyFile, line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(line);
                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return vClients;
    }

    static string _ConverClientObjectToLine(clsBankClient Client, string seprator = "#//#")
    {

        string clsClientRecord = "";
        clsClientRecord += Client.FirstName + seprator;
        clsClientRecord += Client.LastName + seprator;
        clsClientRecord += Client.Email + seprator;
        clsClientRecord += Client.Phone + seprator;
        clsClientRecord += Client.AccountNumber() + seprator;
        clsClientRecord += Client.PinCode + seprator;
        clsClientRecord += to_string(Client.AccountBalance) + seprator;

        return clsClientRecord;
    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients) {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open()) {

            for (clsBankClient C : vClients) {
                // for deletetion
                if (C.MarkedForDeleted() == false) {
                    // only write data that are not marked as deleted
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
       
    }

    void _Update() {
        vector<clsBankClient> _vClients;
        _vClients = _LoadDataFromFile();

        for (clsBankClient& c : _vClients) {
            if (c.AccountNumber() == AccountNumber()) {
                c = *this; //get the updated data that saved in memory 
                break;
            }
        }
        
        _SaveCleintsDataToFile(_vClients); // and save to file 
    }

    void _AddNew() {
        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);// write and append

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }



    string  _convertTranferObjectToLine(float Amount, clsBankClient DestinedClient,
        string UserName,string seperator = "#//#") {
        // we get username ,amount ,and recieved mony client from argumets
        string TransferLogRecord = "";
        TransferLogRecord += clsDate::GetSystemDateTimeToString() + seperator;
        TransferLogRecord += AccountNumber() + seperator;
        TransferLogRecord += DestinedClient.AccountNumber() + seperator;
        TransferLogRecord += to_string(Amount) + seperator;
        TransferLogRecord += to_string(AccountBalance) + seperator;
        TransferLogRecord += to_string(DestinedClient.AccountBalance) + seperator;
        TransferLogRecord += UserName ;


        return TransferLogRecord;




    }

    void _RegisterTransferLog(float amount, clsBankClient DestinedClient, string UserName) {

        string TransferLogRecord = _convertTranferObjectToLine(amount , DestinedClient , UserName);
        fstream MyFile; 
        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open()) {
            MyFile << TransferLogRecord << endl;
            
            MyFile.close();
        }

    }

    struct stTranferLogRecord;

    static  stTranferLogRecord  _convertTransferLogToObject(string Line ,string seperator="#//#") {
        vector <string> _vClients = clsString::Split(Line, seperator);
          
        stTranferLogRecord TransferLogRecord;
        TransferLogRecord.Date = _vClients[0];
        TransferLogRecord.AccountNumber = _vClients[1];
        TransferLogRecord.DistinedAccountnumber = _vClients[2];
        TransferLogRecord.Amount = stoi(_vClients[3]);
        TransferLogRecord.AccountBalance = stoi(_vClients[4]);
        TransferLogRecord.DistinedAccountBalance = stoi(_vClients[5]);
        TransferLogRecord.UserName = _vClients[6];

        return TransferLogRecord; 
        
    }


public:

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    struct stTranferLogRecord
    {
        string Date;
        string AccountNumber;
        string DistinedAccountnumber ;
        float Amount;
        float AccountBalance;
        float DistinedAccountBalance;
        string UserName;
    };

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted() {
        return _MarkClientForDeleted;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }
    

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    /* separte UI Code from Object(logical code)!
    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }*/

   
    bool Transfer(double Amount  , clsBankClient & destinationSource , string UserName) {
        
        if (Amount > AccountBalance) {
            return false;

        }
      
         Withdraw(Amount);
         destinationSource.Deposit(Amount);
        _RegisterTransferLog(Amount, destinationSource, UserName);
        return true;
    }

    void Deposit(double Amount) {
        _AccountBalance += Amount;
        Save();
    }


    bool Withdraw(double Amount) {
        if (Amount > _AccountBalance) {
            return false;
        }
        else {


            _AccountBalance -= Amount;
             Save();
        }
    }

    static clsBankClient  Find(string AccountNumber) {
        //vector<clsBankClient> vClients;

        fstream MyFile;

        MyFile.open("clients.txt", ios::in);

        if (MyFile.is_open()) {
            string line;

            while (getline(MyFile, line))
            {
             
                clsBankClient Client = _ConvertLinetoClientObject(line);
                    if (Client.AccountNumber() == AccountNumber) {
                        MyFile.close();
                        return Client;
                }
            }

           
        }

        return _GetEmptyClientObject();
    }


    static clsBankClient  Find(string AccountNumber , string PinCode) {
        //vector<clsBankClient> vClients;

        fstream MyFile;

        MyFile.open("clients.txt", ios::in);

        if (MyFile.is_open()) {
            string line;

            while (getline(MyFile, line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode) {
                    MyFile.close();
                    return Client;
                }
            }


        }

        return _GetEmptyClientObject();
    }

    static bool IsClientExsit(string AccountNumber) {
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        return (!Client.IsEmpty());
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 , svFailedAccountNumberExist = 3 };

    enSaveResults Save() {
        switch (_Mode)
        {
        case enMode::EmptyMode :
        
        {
            if (IsEmpty()) {

                return enSaveResults::svFaildEmptyObject;
            }
        }
        
        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;
            break;

        
        case enMode::AddNewMode:
            if (clsBankClient::IsClientExsit(_AccountNumber)) {
                return enSaveResults::svFailedAccountNumberExist;

            }
            else {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            
            }

            break;
           
        }

        
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber) {

        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete() {
        vector<clsBankClient> _vClients;
        _vClients = _LoadDataFromFile();

        for (clsBankClient& C : _vClients) {
            if (C.AccountNumber() == AccountNumber()) {
                C._MarkClientForDeleted = true;
                break;
            }
        }

        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject(); // empty the object in memory

        return true;
    }

    static vector <clsBankClient> GetClientsList() {
        return _LoadDataFromFile();
    }

    
    static double GetTotalBalances() {
        vector <clsBankClient> _vClients;
        _vClients = clsBankClient::GetClientsList();

        double TotalBalances= 0;

        for (clsBankClient Client : _vClients) {
            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;

    }



    static  vector <stTranferLogRecord> GetTransferLogList() {

        vector<stTranferLogRecord> _vTranferLogClients;
        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);

        if (MyFile.is_open()) {
            string Line;
            stTranferLogRecord Client1;

            while (getline(MyFile, Line)) {
                Client1 = _convertTransferLogToObject(Line);
                _vTranferLogClients.push_back(Client1);

            }

            MyFile.close();
        }

        return _vTranferLogClients;
    }


    


};

