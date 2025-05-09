//
// Created by ahmad on 4/28/2024.
//

#include "Users.h"
using namespace std;
// Constructor to initialize Users object
Users::Users(string &name, Menu *menu): name(name), menu(menu){}
// Display the entire menu
void Users::displayWholeMenu(ostream& out){
    this->menu->displayMenu(out);
}
// Display the vegetarian menu
void Users::displayVegetarianMenu(std::ostream &out) {
    this->menu->displayVeganVegeterian(out);
}
// Display the special offer menu
void Users::displaySpecialOfferMenu(std::ostream &out) {
    //this->menu->setOffer();
    this->menu->displaySpecialOffer(out);
}



