//
// Created by ahmad on 4/28/2024.
//

/*-- Users.h ---------------------------------------------------------------

This header file defines the Users class, representing users in the restaurant management system.
Basic operations include:
Constructor: Initializes a Users object with a name and a reference to the menu.
login: Logs in the user.
displayCommandLine: Displays the command-line interface for the user.
displayWholeMenu: Displays the entire menu.
displaySpecialOfferMenu: Displays the special offer menu.
displayVegetarianMenu: Displays the vegetarian menu.

-------------------------------------------------------------------------*/
#ifndef DSPROJ_USERS_H
#define DSPROJ_USERS_H

#include "Menu.h"
#include <vector>
#include <string>

class Users {

public:

    Users(string &name, Menu * menu);
    /*---------------------------------------------------------------------
    Precondition: The name parameter must be a valid string reference. The menu parameter must point to a valid Menu object.
    Postcondition: A Users object is constructed with the provided name and menu.
    ---------------------------------------------------------------------*/

    virtual bool login(const string& inputUsername, const string& inputPassword) = 0;
    /*---------------------------------------------------------------------
    Precondition: None.
    Postcondition: Returns true if the user successfully logs in; otherwise, returns false.
    ---------------------------------------------------------------------*/

    virtual void displayCommandLine(ostream& out)= 0;
    /*---------------------------------------------------------------------
    Precondition: The out parameter must reference a valid ostream object.
    Postcondition: Displays the command-line interface for the user.
    ---------------------------------------------------------------------*/

    void displayWholeMenu(ostream& out);
    /*---------------------------------------------------------------------
       Precondition: The out parameter must reference a valid ostream object.
       Postcondition: Displays the entire menu to the specified output stream.
       ---------------------------------------------------------------------*/


    void displaySpecialOfferMenu(ostream& out);
    /*---------------------------------------------------------------------
         Precondition: The out parameter must reference a valid ostream object.
         Postcondition: Displays the special offer menu to the specified output stream.
         ---------------------------------------------------------------------*/

    void displayVegetarianMenu(ostream& out);
    /*---------------------------------------------------------------------
    Precondition: The out parameter must reference a valid ostream object.
    Postcondition: Displays the vegetarian menu to the specified output stream.
    ---------------------------------------------------------------------*/


protected:
    string &name;
    Menu * menu;
};


#endif //DSPROJ_USERS_H
