#pragma once
#include <iostream>
#include"Global.h"
#include"clsDate.h"

using namespace std;

class clsScreen

{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        
        
        //_drawScreenUser();

        // instructor  sol
        cout << "\t\t\t\t\t User: " << CurrentUser.UserName << "\n";
        cout << "\t\t\t\t\t Date: " << clsDate::DateToString(clsDate()) << "\n";

    }
    static void _drawScreenUser() {

       
        ShowUser();
        ShowDate();
    }

    static bool CheckAccessRight(clsUser::enPermissions Permissions){
        if (!CurrentUser.CheckAccessPermission(Permissions)) {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else {
            return true;
        }
    
    }


    static void ShowUser() {
        cout << "\n\t\t\t\t\t UserName: " << CurrentUser.UserName << endl;
    }

    static void ShowDate() {
        clsDate date;
        date.GetSystemDate();
        cout << "\n\t\t\t\t\t Date: "; date.Print(); cout << endl;
    }

};
