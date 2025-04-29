// class-3(BankClient).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"clsBankClient.h";
#include"clsInputValidate.h"
#include<iomanip>
#include"clsUtil.h";
#include"clsLoginScreen.h";
#include"clsCurrency.h"



int main()
{
   /* clsBankClient Client = clsBankClient::Find("A101"); // first it find in object , then assign to object
    Client.Print();

    clsBankClient Client2 = clsBankClient::Find("A101", "1234");
    Client2.Print();


    cout << Client2.IsClientExsting("A123");
    */

 
    //UpdateClient();

    //AddNewClient();

    //DeleteClient();

    //ShowClientsList();

    //ShowTotalBalances();

    while (true) {
        
    
        if (!clsLoginScreen::ShowLoginScreen()) { // if login return not true exit the programm
            break;
        };

       
    }

 
}
