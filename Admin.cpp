//
// Created by ahmad on 4/28/2024.
//

#include "Admin.h"
#include "Menu.h"
#include "MenuItem.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <set>

using namespace std;

typedef MenuItem* MenuItemPtr;
// Constants for default admin credentials
const string username = "Admin";
const string password = "123";
// Constructor to initialize Admin object
Admin::Admin(string &name, Menu *menu) : Users(name, menu) {}
// Method to authenticate admin login
bool Admin::login(const string& inputUsername, const string& inputPassword) {
    // Check if input username and password match default admin credentials
    if ((inputUsername == username) && (inputPassword == password)) {
        cout << "Login successful! Welcome, " << username << "!" << endl;
        return true;
    } else {
        cout << "Login failed! Incorrect username or password." << endl;
        return false;
    }
}

// Display command line method
void Admin::displayCommandLine(ostream& out) {
    out<<"The following are the commands that the user can use:"<<'\n';
    out<<"1-Display Menu"<<'\n';
    out<<"2-Display Vegiterian/Vegan Menu"<<'\n';
    out<<"3-Display Special Offer"<<'\n';
    out<<"4-Add Food Item to menu"<<'\n';
    out<<"5-Remove Food Item from menu"<<'\n';
    out<<"6-Modify Food Item from menu"<<'\n';
}
// Method to modify a menu item
void Admin::modifyMenuItem(const MenuItem& item){
    // Check if the item exists in the menu
    if (menu->getItem(item.getId()) != nullptr)
        menu->modifyMenuItem(item);
    else
        cerr<<"Not Valid Input"<<endl;
}

// Method to add a new menu item
void Admin::addMenuItem(const MenuItem& item){
    // Check if the item ID is available
    if (menu->getItem(item.getId()) == nullptr)
        menu->add_MenuItem(item);
    else
        cerr<<"Id is taken"<<endl;

}
// Method to delete a menu item
void Admin::deleteMenuItem(unsigned short id){
    // Check if the item exists in the menu
    if (menu->getItem(id) != nullptr)
        menu->remove_Menu_Item(id);
    else
        cerr<<"Id is not valid"<<endl;

}




