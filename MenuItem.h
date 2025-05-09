//
// Created by ahmad on 4/26/2024.
//

/*-- MenuItem.h -----------------------------------------------------------

This header file defines the MenuItem class for representing items in a menu.
Basic operations are:
Constructor: Constructs a MenuItem object with specified attributes.
Getter methods: Retrieve attributes such as id, name, price, type, category, and ingredients.
Setter methods: Set attributes such as id, name, price, type, category, and ingredients.
Assignment operator: Assigns the attributes of one MenuItem object to another.
Output operator: Overloads the << operator to display the MenuItem object.

-------------------------------------------------------------------------*/

#ifndef DSPROJ_MENUITEM_H
#define DSPROJ_MENUITEM_H

#include <iostream>
#include <vector>

using namespace std;



class MenuItem {
private:

    unsigned short id; // Unique identifier for the menu item.
    std::string name; // Name of the menu item.
    float price; // Price of the menu item.
    char type; // Type of the menu item ('V' for vegetarian, 'N' for non-vegetarian).
    char category; // Category of the menu item ( 'S' for starter, 'M' for main course).
    vector<string> ingredients; // Ingredients used in the menu item.
public:
    MenuItem(unsigned short id, string name, float price, char type, char category, vector<string> ingredients);
    /*---------------------------------------------------------------------
    Precondition:  None.

    Postcondition: Constructs a MenuItem object with the given id, name,
                   price, type, category, and ingredients.
    ---------------------------------------------------------------------*/

    unsigned short getId() const;
    /*---------------------------------------------------------------------
Precondition:  None.

Postcondition: Returns the id of the MenuItem.
---------------------------------------------------------------------*/

    string getName() const;
    /*---------------------------------------------------------------------
Precondition:  None.

Postcondition: Returns the name of the MenuItem.
---------------------------------------------------------------------*/

    float getPrice() const;
    /*---------------------------------------------------------------------
     Precondition:  None.

     Postcondition: Returns the price of the MenuItem.
     ---------------------------------------------------------------------*/

    char getType() const;
    /*---------------------------------------------------------------------
     Precondition:  None.

     Postcondition: Returns the type of the MenuItem.
     ---------------------------------------------------------------------*/

    char getCategory() const;
    /*---------------------------------------------------------------------
  Precondition:  None.

  Postcondition: Returns the category of the MenuItem.
  ---------------------------------------------------------------------*/

    vector<string> getIngredients() const;
    /*---------------------------------------------------------------------
    Precondition:  None.

    Postcondition: Returns the ingredients of the MenuItem.
    ---------------------------------------------------------------------*/

    void setId(unsigned short id);
    /*---------------------------------------------------------------------
     Precondition:  Valid id value.

     Postcondition: Sets the id of the MenuItem to the given value.
     ---------------------------------------------------------------------*/

    void setName(string& name);
    /*---------------------------------------------------------------------
     Precondition:  Valid name value.

     Postcondition: Sets the name of the MenuItem to the given value.
     ---------------------------------------------------------------------*/

    void setPrice(float price);
    /*---------------------------------------------------------------------
   Precondition:  Valid price value.

   Postcondition: Sets the price of the MenuItem to the given value.
   ---------------------------------------------------------------------*/

    void setType(char type);
    /*---------------------------------------------------------------------
    Precondition:  Valid type value.

    Postcondition: Sets the type of the MenuItem to the given value.
    ---------------------------------------------------------------------*/

    void setCategory(char category);
    /*---------------------------------------------------------------------
    Precondition:  Valid category value.

    Postcondition: Sets the category of the MenuItem to the given value.
    ---------------------------------------------------------------------*/

    void setIngredients(vector<string> ingredients);
    /*---------------------------------------------------------------------
     Precondition:  Valid ingredients vector.

     Postcondition: Sets the ingredients of the MenuItem to the given vector.
     ---------------------------------------------------------------------*/

    void setMenuItem(unsigned short id, std::string name, double price, char type
            , char category, vector<string> ingredients);
 /*---------------------------------------------------------------------
   Precondition:  Valid id, name, price, type, category, and ingredients.

   Postcondition: Sets the id, name, price, type, category, and ingredients
                  of the MenuItem to the given values.
   ---------------------------------------------------------------------*/

    MenuItem& operator=(const MenuItem& menuItem);
 /*---------------------------------------------------------------------
Precondition:  MenuItem object to assign.

Postcondition: Assigns the values of the given MenuItem to the current
               MenuItem object.
---------------------------------------------------------------------*/

    MenuItem& operator<<(const MenuItem& menuItem);
 /*---------------------------------------------------------------------
Precondition:  MenuItem object to append.

Postcondition: Appends the values of the given MenuItem to the current
               MenuItem object.
---------------------------------------------------------------------*/

    bool operator==(const MenuItem& righthandside) const;
 /*---------------------------------------------------------------------
  Precondition:  MenuItem object to compare.

  Postcondition: Returns true if the given MenuItem is equal to the
                 current MenuItem object, false otherwise.
  ---------------------------------------------------------------------*/

    bool operator>=(const MenuItem& righthandside) const;
 /*---------------------------------------------------------------------
 Precondition:  MenuItem object to compare.

 Postcondition: Returns true if the given MenuItem is greater than or
                equal to the current MenuItem object, false otherwise.
 ---------------------------------------------------------------------*/

    friend ostream& operator<<(ostream &out, const MenuItem &menuItem);

    /*---------------------------------------------------------------------
   Precondition:  Output stream and MenuItem object to display.

   Postcondition: Overloads the << operator to display the contents of the
                  MenuItem on the output stream.
   ---------------------------------------------------------------------*/


};


#endif //DSPROJ_MENUITEM_H
