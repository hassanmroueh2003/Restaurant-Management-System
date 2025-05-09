//
// Created by ahmad on 4/27/2024.
//
/*-- Menu.h ---------------------------------------------------------------

This header file defines the Menu class for managing a restaurant menu.
Basic operations include:
Constructor: Initializes a Menu object with menu items loaded from a file.
Destructor: Destroys a Menu object, freeing memory.
add_MenuItem: Adds a MenuItem to the Menu.
getItem: Retrieves a MenuItem by its ID.
modifyMenuItem: Modifies a MenuItem in the Menu.
remove_Menu_Item: Removes a MenuItem from the Menu.
InitMenu: Initializes the Menu with menu items from a file.
displayMenu: Displays the entire Menu.
displaySpecialOffer: Displays the special offer items in the Menu.
displayVeganVegetarian: Displays vegan and vegetarian items in the Menu.
setOffer: Sets a special offer for menu items.
order_item: Orders a MenuItem from the Menu.

-------------------------------------------------------------------------*/
#include "MenuItem.h"
#include <fstream>
#include <vector>
#include "LinkedList.h"

#ifndef DSPROJ_MENU_H
#define DSPROJ_MENU_H


using namespace std;
const int menuSize = 4;
typedef MenuItem* MenuItemPtr;


class Menu {

public:

    Menu();
    /*---------------------------------------------------------------------
Precondition:  Valid file path to load menu items from.

Postcondition: Constructs a Menu object and initializes it with menu
               items loaded from the specified file.
---------------------------------------------------------------------*/
    ~Menu();
    /*---------------------------------------------------------------------
    Precondition:  None.

    Postcondition: Destroys the Menu object, freeing memory.
    ---------------------------------------------------------------------*/
    void add_MenuItem(const MenuItem& item);
    /*---------------------------------------------------------------------
Precondition:  Valid MenuItem object to add.

Postcondition: Adds the given MenuItem to the Menu.
---------------------------------------------------------------------*/
    MenuItemPtr getItem(unsigned short id);
    /*---------------------------------------------------------------------
   Precondition:  Valid id of the MenuItem to retrieve.

   Postcondition: Returns a pointer to the MenuItem with the specified id.
   ---------------------------------------------------------------------*/
    void modifyMenuItem(const MenuItem& item);
    /*---------------------------------------------------------------------
Precondition:  Valid MenuItem object to modify.

Postcondition: Modifies the MenuItem in the Menu with the same id as
              the given MenuItem.
---------------------------------------------------------------------*/
    void remove_Menu_Item(unsigned short itemId);
    /*---------------------------------------------------------------------
Precondition:  Valid id of the MenuItem to remove.

Postcondition: Removes the MenuItem with the specified id from the Menu.
---------------------------------------------------------------------*/

    void InitMenu(const string& filename);
    /*---------------------------------------------------------------------
   Precondition:  Valid file path to load menu items from.

   Postcondition: Initializes the Menu with menu items loaded from the
                  specified file.
   ---------------------------------------------------------------------*/
    void addIdsToNewFile(const string& source,const string& destinantion);
    /*---------------------------------------------------------------------
        Precondition: The source parameter must specify the path to an existing file containing menu items. The destination parameter must specify the path to the new file where the modified menu items will be written.
        Postcondition: Reads menu items from the source file, assigns unique IDs to each item based on category, and writes the modified items with IDs to the destination file.
        ---------------------------------------------------------------------*/


    void displayMenu(ostream& out);
    /*---------------------------------------------------------------------
   Precondition:  Output stream to display the Menu.

   Postcondition: Displays the Menu on the output stream.
   ---------------------------------------------------------------------*/

    void displaySpecialOffer(ostream& out);
    /*---------------------------------------------------------------------
 Precondition:  Output stream to display the special offer.

 Postcondition: Displays the special offer on the output stream.
 ---------------------------------------------------------------------*/

    void displayVeganVegeterian(ostream& out);

    /*---------------------------------------------------------------------
      Precondition:  Output stream to display vegan and vegetarian items.

      Postcondition: Displays vegan and vegetarian items on the output stream.
      ---------------------------------------------------------------------*/


    void setOffer();
    /*---------------------------------------------------------------------
Precondition:  None.

Postcondition: Sets a special offer for menu items.
---------------------------------------------------------------------*/

    void order_item(int itemId);
    /*---------------------------------------------------------------------
Precondition:  Valid id of the MenuItem to order.

Postcondition: Orders the MenuItem with the specified id.
---------------------------------------------------------------------*/



private:
    // - `categories`: An array of pointers to `LinkedList` objects. Each linked list holds `MenuItem` objects
    //   belonging to a specific category (up to `menuSize` categories). This allows efficient organization and
    //   retrieval of menu items based on their category.

    LinkedList<MenuItem>* categories[menuSize];
    // - `veganVegetarianCat`: Another array of pointers to `LinkedList` objects. Similar to `categories`,
    //   each linked list holds the IDs of menu items that are vegan or vegetarian.


    LinkedList<unsigned short>* veganVegetarianCat[menuSize];
    // - `offer_items`: A structure to store information about items in the current special offer.
    //   - `quantity`: The quantity of the item available in the offer.
    //   - `id`: The ID of the menu item included in the offer.
    struct offer_items {
        int quantity;
        unsigned short id;//change to id
    };
    // - `specialOffer`: A vector to hold multiple `offer_items` structures, representing the current special
    //   offer items.
    vector<offer_items> specialOffer;
    int getRandomId(int categoryNb);
    /*---------------------------------------------------------------------
Precondition: - `categoryNb`: This parameter must be a valid category number.

Postcondition: -If `categoryNb` is valid, the function returns a random integer ID that is associated
    with menu items in that category.
- If `categoryNb` is invalid (outside the valid range),  it returns  an arbitrary value .
---------------------------------------------------------------------*/
    MenuItem createItemformStr(const string &line);
    /*---------------------------------------------------------------------
Precondition: line`: This parameter is a constant string reference that represents a line of text expected to be
    in a specific format suitable for parsing into a `MenuItem` object. The exact format of the line is
//   dependent on a certain format of the menu text file and  contains information about the menu item
Postcondition:   -The provided `line` is  parsed and the function returns a
 pointer to a newly created `MenuItem` object that holds the parsed information.

---------------------------------------------------------------------*/

};

typedef Menu* MenuPtr;
#endif //DSPROJ_MENU_H