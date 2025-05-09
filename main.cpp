/*
Project: Restaurant Management System
    Description: This program simulates a restaurant management system where users can log in as either Admin or Client.
                 Admins can perform operations such as managing the menu items, while clients can view the menu, add items to their cart, and finalize their bill.
                 The program uses a Menu class to manage menu items and a Users class as a base class for Admin and Client classes.
                 Users can log in, view the menu, and perform other operations based on their role.

    File: main.cpp
    Created by: Ahmad and Hassan
    Created on: 4/28/2024
*/

#include <iostream>
#include <memory>
#include <fstream>
#include <limits>
#include <sstream>
#include <regex>
#include "Client.h"
#include "Admin.h"

using namespace std;

int main() {
    // Declare variables and objects
    string userType;
    string name;
    Menu menu;
    unsigned short id = 0;
    float price = 0.0;
    char category = 'm', type = 'o';
    string ing = "";
    vector<string> ingVector;
    MenuItem item(id, name, price, type, category, ingVector);

    // Initialize menu from file
    menu.InitMenu("menuItems.txt");
    // Prompt user to choose user type
    do {


        cout << "Do you want to log in as an Admin or a Client? (Enter 'Admin' or 'Client'): ";
        getline(cin, userType);

        if (userType != "Admin" && userType != "Client") {
            cout << "Invalid input. Please start over and enter 'Admin' or 'Client'." << endl;
        }

    }while(userType != "Admin" && userType != "Client");
    // User login and menu operations based on user type
        if (userType == "Admin") {
            // Admin login
            Admin user1((string &) "ahmad", &menu);
            string username,password;


                cout << "Please log in to continue." << endl;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
            bool typeusr = user1.login(username,password);
            cout<<password;
            cout<<username;
            if(typeusr == false) {
                exit(-1);
            }
            user1.displayCommandLine(cout);
            int choice;
            // Admin menu operations loop
            do {
                cout << "Enter your choice: (1-6)"<<'\n';
                cin >> choice;
                switch (choice) {
                    case 1:
                        user1.displayWholeMenu(cout);
                        break;
                    case 2:
                        user1.displayVegetarianMenu(cout);

                        break;
                    case 3:
                        user1.displaySpecialOfferMenu(cout);
                        break;

                    case 4:
                        // Add new menu item
                        cout<<"Please enter the item details for the newly added item"<<'\n';
                        cout<<"Enter item id (100->499)"<<'\n';
                        // Input item details
                        cin>>id;
                        cout<<'\n'<<"Enter item name (no spaces)"<<'\n';
                        cin>>name;
                        cout<<'\n'<<"Enter item category (a, m, d, b)"<<'\n';
                        cin>>category;
                        cout<<'\n'<<"Enter item type (o, v, g)"<<'\n';
                        cin>>type;
                        cout<<'\n'<<"Enter item price"<<'\n';
                        cin>>price;
                        cout<<'\n'<<"Enter item ingredients one by one (type x to stop adding ingredients):"<<'\n';
                        do {
                            cin >> ing;
                            if (ing != "x")
                                ingVector.push_back(ing);
                            cout << endl;
                        }while(ing != "x" || ingVector.size() == 8);
                        item.setMenuItem(id,name, price, type, category, ingVector);
                        // Add item to menu
                        user1.addMenuItem(item);
                        break;
                    case 5:
                        // Delete menu item
                        cout<<"Enter item id (100->499) for the item to be deleted"<<'\n';
                        cin>>id;
                        user1.deleteMenuItem(id);
                        break;
                    case 6:
                        // Modify menu item
                        cout<<"Please enter the new item details for the modified item"<<'\n';
                        cout<<"Enter item id (100->499)"<<'\n';
                        // Input modified item details
                        cin>>id;
                        cout<<'\n'<<"Enter item name"<<'\n';
                        cin>>name;
                        cout<<'\n'<<"Enter item category (a, m, d, b)"<<'\n';
                        scanf(" %c", &category);
                        cout<<'\n'<<"Enter item type (o, v, g)"<<'\n';
                        scanf(" %c", &type);
                        cout<<'\n'<<"Enter item price"<<'\n';
                        cin>>price;
                        cout<<'\n'<<"Enter item ingrediants one by one (type x to stop adding ingrediants):"<<'\n';
                        do {
                            cin >> ing;
                            if (ing != "x")
                                ingVector.push_back(ing);
                            cout << endl;
                        }while(ing != "x" || ingVector.size() == 8);

                        item.setMenuItem(id,name, price, type, category, ingVector);
                        // Modify item in menu
                        user1.modifyMenuItem(item);
                        break;
                    default:
                        cout << "Invalid choice. Please enter a number between 1 and 6.\n";
                        break;
                }
            } while (choice != 0);
        } else if (userType == "Client") {
            // Client login
            Client client1((string &) "ahmad", &menu);
            string username1,password1;
            cout << "Please log in to continue." << endl;
            cout << "Username: ";
            cin >> username1;
            cout << "Password: ";
            cin >> password1;
            client1.login(username1,password1);

            client1.displayCommandLine(cout);
            int choice;
            // Client menu operations loop
            do {
                cout << "Enter your choice: (1-6)"<<'\n';
                cin >> choice;
                switch (choice) {
                    case 1:
                        client1.displayWholeMenu(cout);
                        break;
                    case 2:
                        client1.displayVegetarianMenu(cout);

                        break;
                    case 3:
                        client1.displaySpecialOfferMenu(cout);
                        break;

                    case 4:
                        cout<<"Please choose the item ID you want to add in your cart"<<'\n';
                        // Add item to cart
                        client1.addToCart();
                        break;
                    case 5:
                        cout<<"Please choose the item ID you want to remove from your cart"<<'\n';
                        // Remove item from cart
                        client1.removeFromCart();
                        break;

                    case 6:
                        // View cart
                        client1.viewCart(cout);

                        break;
                    case 7:
                        // Finalize bill
                        client1.finalizeBill();

                        break;
                    default:
                        cout << "Invalid choice. Please enter a number between 1 and 6.\n";
                        break;
                }
            } while (choice != 0);

        } else {
            std::cout << "Invalid user type. Please enter 'admin' or 'client'.";
        }


    }
