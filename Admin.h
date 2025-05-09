//
// Created by ahmad on 4/28/2024.
//

/*-- Admin.h ---------------------------------------------------------------

This header file defines the Admin class, which represents an administrator user in the restaurant management system.
Basic operations include:
Constructor: Initializes an Admin object with a name and a reference to the menu.
login: Logs in the administrator.
displayCommandLine: Displays the command-line interface for the administrator.
addMenuItem: Adds a new menu item to the menu.
deleteMenuItem: Deletes a menu item from the menu.
modifyMenuItem: Modifies an existing menu item.

-------------------------------------------------------------------------*/
#ifndef DSPROJ_ADMIN_H
#define DSPROJ_ADMIN_H


#include <iostream>
#include "Users.h"

class Admin : public Users {
public:

    Admin(string &name, Menu *menu);
    /*---------------------------------------------------------------------
    Precondition: The name parameter must be a valid string reference. The menu parameter must point to a valid Menu object.
    Postcondition: An Admin object is constructed with the provided name and menu.
    ---------------------------------------------------------------------*/

    bool login(const string& inputUsername, const string& inputPassword) override;
    /*---------------------------------------------------------------------
    Precondition: None.
    Postcondition: Returns true if the admin successfully logs in; otherwise, returns false.
    ---------------------------------------------------------------------*/

    void displayCommandLine(ostream& out) override;
    /*---------------------------------------------------------------------
        Precondition: The out parameter must reference a valid ostream object.
        Postcondition: Displays the command-line interface for the admin.
     ---------------------------------------------------------------------*/

    void addMenuItem(const MenuItem& item);
    /*---------------------------------------------------------------------
    Precondition: The item parameter must be a valid MenuItem object.
    Postcondition: Adds a new menu item to the menu.
    ---------------------------------------------------------------------*/

    void deleteMenuItem(unsigned short id);
    /*---------------------------------------------------------------------
    Precondition: The id parameter must be a valid unsigned short representing the ID of the item to be deleted.
    Postcondition: Deletes the menu item with the specified ID from the menu.
    ---------------------------------------------------------------------*/

    void modifyMenuItem(const MenuItem& item);
    /*---------------------------------------------------------------------
    Precondition: The item parameter must be a valid MenuItem object.
    Postcondition: Modifies an existing menu item with the provided item details.
    ---------------------------------------------------------------------*/

};


#endif //DSPROJ_ADMIN_H
