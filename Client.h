//
// Created by ahmad on 4/28/2024.
//
/*-- Client.h ---------------------------------------------------------------

This header file defines the Client class, representing a client user in the restaurant management system.
Basic operations include:
Constructor: Initializes a Client object with a name and a reference to the menu.
login: Logs in the client.
displayCommandLine: Displays the command-line interface for the client.
addToCart: Adds an item to the client's cart.
removeFromCart: Removes an item from the client's cart.
viewCart: Displays the client's cart.
finalizeBill: Finalizes the bill for the client's order.

-------------------------------------------------------------------------*/
#ifndef DSPROJ_CLIENT_H
#define DSPROJ_CLIENT_H

#include <iostream>
#include "Users.h"
#include "LinkedList.h"
using namespace std;

class Client : public Users {
public:
    Client(string &name, Menu *menu);
    /*---------------------------------------------------------------------
    Precondition: The name parameter must be a valid string reference. The menu parameter must point to a valid Menu object.
    Postcondition: A Client object is constructed with the provided name and menu.
    ---------------------------------------------------------------------*/

    bool login(const string& inputUsername, const string& inputPassword) override;
    /*---------------------------------------------------------------------
    Precondition: None.
    Postcondition: Returns true if the client successfully logs in; otherwise, returns false.
    ---------------------------------------------------------------------*/

    void displayCommandLine(ostream& out) override;
    /*---------------------------------------------------------------------
       Precondition: The out parameter must reference a valid ostream object.
       Postcondition: Displays the command-line interface for the client.
       ---------------------------------------------------------------------*/

    void addToCart();
    /*---------------------------------------------------------------------
    Precondition: None.
    Postcondition: Adds an item to the client's cart.
    ---------------------------------------------------------------------*/

    void removeFromCart();
    /*---------------------------------------------------------------------
    Precondition: None.
    Postcondition: Removes an item from the client's cart.
    ---------------------------------------------------------------------*/

    void viewCart(ostream& out);
    /*---------------------------------------------------------------------
    Precondition: The out parameter must reference a valid ostream object.
    Postcondition: Displays the client's cart to the specified output stream.
    ---------------------------------------------------------------------*/

    void finalizeBill();
    /*---------------------------------------------------------------------
        Precondition: None.
        Postcondition: Finalizes the bill for the client's order.
        ---------------------------------------------------------------------*/


private:
    LinkedList<unsigned short>* cart;

};

#endif //DSPROJ_CLIENT_H
