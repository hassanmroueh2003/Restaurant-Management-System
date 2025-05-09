//
// Created by ahmad on 4/28/2024.
//

#include "Client.h"
#include "Menu.h"
#include "MenuItem.h"
#include <iostream>
#include <iomanip>
#include <set>

using namespace std;

typedef MenuItem* MenuItemPtr;

// Constructor to initialize a Client object
Client::Client(string &name, Menu *menu) : Users(name, menu) {
    // Initialize the client's cart
    cart = new LinkedList<unsigned short>();
}

// Login method
bool Client::login(const string& inputUsername, const string& inputPassword) {

    // This method can be implemented to authenticate the client's login if needed
    // For simplicity, it always returns true in this example

    return true;
}


// Display command line method
void Client::displayCommandLine(ostream& out) {
    out<<"The following are the commands that the user can use:"<<'\n';
    out<<"1-Display Menu"<<'\n';
    out<<"2-Display Vegiterian/Vegan Menu"<<'\n';
    out<<"3-Display Special Offer"<<'\n';
    out<<"4-Add Food Item to Cart"<<'\n';
    out<<"5-Remove Food Item from Cart"<<'\n';
    out<<"6-View Cart"<<'\n';
    out<<"7-Get Reciept and Close the Cart"<<'\n';
}
// Method to add a food item to the client's cart
void Client::addToCart() {
        string id;
        cin >> id;
        unsigned short num = stoi(id);
        MenuItemPtr item = menu->getItem(num);

        if (item != nullptr) {
            cart->insertSorted(item->getId());

        } else
            cerr<<"The Id is not valid"<<'\n';

}
// Method to display the client's cart
void Client::viewCart(ostream& out) {


    set<unsigned short> uid;
    out<<"Cart:"<<'\n';
    for (unsigned i = 0; i < cart->getSize(); i++) {
        uid.insert(*cart->get(i));
    }

    for (unsigned short id : uid) {
        out << "Id: " << id << setw(50) << "Number of each item : "<< cart->countOccurences(id) << '\n';
        out << string(25, '-')<<'\n';
        }
    }
// Method to remove a food item from the client's cart
void Client::removeFromCart() {
    string idStr;
    unsigned short id;


    cout << string(100, '#') << '\n';
    cout << string(100, '-') << '\n';
    cout << "Enter the ID of the item to be removed: ";
    cin >> idStr;
    cout << string(100, '-') << '\n';

    try {
        id = stoi(idStr);
    } catch (invalid_argument &e) {
        cerr << "[!]Invalid ID input." << endl;
        return;
    }
    MenuItemPtr item = menu->getItem(id);
    if (item == nullptr) {
        cerr << "[!]Item not found." << endl;
        return;
    }


        cout << "Item removed from cart." << endl;
        cart->removeObj(id);

}
// Method to finalize the bill for the client's cart
void Client::finalizeBill(){
    viewCart(cout);
    float sum = 0;
    for(int i = 0; i < cart->getSize(); i++){
        sum += menu->getItem(*cart->get(i))->getPrice();
        menu->order_item(menu->getItem(*cart->get(i))->getId());
    }
    cout<<"Your final bill is "<<sum<<" $\n";

}



