//
// Created by ahmad on 4/27/2024.
//

#include "Menu.h"
#include "MenuItem.h"
#include "LinkedList.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>


using namespace std;
// Menu Class

// Constructor: Initializes the menu with a specified file path

Menu::Menu() {
    // Initialize special offer vector with empty offer_items objects
    for (int i = 0; i < menuSize; ++i) {

        categories[i] = new LinkedList<MenuItem>();
        veganVegetarianCat[i] = new LinkedList<unsigned short>();

    }
    specialOffer = vector<offer_items>(8);
    //setOffer();

}



// Destructor: Deallocates memory used by the menu
Menu::~Menu() {
    // Delete each category linked list
    for (int i = 0; i < menuSize; i++) {
        delete categories[i];
    }
    // Clear the special offer vector
    specialOffer.clear();
}
// Menu Initialization

// Reads menu items from a file and populates the menu data structures

void Menu::InitMenu(const string& source) {

    addIdsToNewFile(source, "modified_menuItems.txt");//this function adds ids for each menu item to a new file
    int size = 4; // Assuming there are 4 categories
    ifstream MyFile;
    MyFile.open("modified_menuItems.txt");
    char categ;
    // Check if file opened successfully
    if(!MyFile.is_open())
        cout<<"error \n";
    else {
        // Loop through each category
        for(int i =0 ; i < size; i++) {
            switch (i) {
                case 0: {
                    categ='a';
                } break;
                case 1: {
                    categ='m';
                } break;
                case 2: {
                    categ='d';
                } break;
                case 3: {
                    categ='b';
                } break;
                default: categ=' ';
            }

            string line;
            // Read each line from the file
            // Reset the file pointer to the beginning of the file

            MyFile.close();
            MyFile.open("modified_menuItems.txt");
            while(getline(MyFile, line)) {
               // cout<<"\n enter loop";

                // Parse the line and create a MenuItem object
                MenuItem newMenu = createItemformStr(line);
                if(newMenu.getCategory()== categ)
                    // Insert the item into the corresponding category linked list (sorted)
                {
                    categories[i]->insertSorted(newMenu);

                }
            }

                MyFile.close();
        }


    }
    setOffer();



}


// Parsing Menu Item from String

// Parses a line of text from the menu file and creates a MenuItem object

MenuItem Menu::createItemformStr(const string &line){
    int i = 0;
    float price = 0;
    string name;
    char typeChar, categoryChar;
    vector<string> new_ingredients;
    int new_id = 0;

    // Parsing name
    while (line[i] != ',') {
        name += line[i];
        i++;
    }
    i += 2; // Skip ", "

    // Parsing type and category
    typeChar = line[i];
    i += 2;
    categoryChar = line[i];
    i += 2;

    // Parsing price
    string priceString;
    while (line[i] != ' ') {
        priceString += line[i];
        i++;
    }
    price = stof(priceString);
    i++; // Move to the ingredients part

    // Parsing ingredients
    // Parsing ingredients
    string ingredient;
    while (!isdigit(line[i])) {
        if (line[i] == ',') {
            new_ingredients.push_back(ingredient);
            ingredient.clear();
        } else {
            ingredient += line[i];
        }
        i++;
    }
    // Add the last ingredient
    if (!ingredient.empty()) {
        new_ingredients.push_back(ingredient);
    }

    // Move to ID part
    while (!isdigit(line[i])) {
        i++;
    }
    while (isdigit(line[i])) {
        new_id = new_id * 10 + (line[i] - '0');
        i++;
    }

   /* MenuItem m1();
    m1.setName(name);
    m1.setType(typeChar);
    m1.setCategory(categoryChar);
    m1.setPrice(price);
    m1.setId(new_id);
    m1.setCategory(categoryChar);
    m1.setIngredients(new_ingredients); */
    return MenuItem(new_id, name, price, typeChar, categoryChar, new_ingredients);
}

// Function to Add IDs to a New File

// This function takes a source file path and a destination file path as input.
// It reads the source file line by line, parses the category character,
// and assigns a unique ID based on the category. The ID is then appended
// to the line and written to the destination file.

void Menu::addIdsToNewFile(const string& source,const string& destinantion) {
    int i = 0;
    unsigned short id = 0, firstDigit =0 , otherDigits=0 ;
    unsigned short Appetizers = 0 , Main_Dishes = 0, Desserts = 0, Beverages = 0;
    ifstream MyFile; //The source file to read data from
    ofstream newFile; //The destination file to write to
    // Open the source and destination files
    MyFile.open(source);
    newFile.open(destinantion);
    // Check if the source file opened successfully
    if(!MyFile.is_open())
        cout<<"error \n";
    else {
        string line;
        while(getline(MyFile, line)) {
            i = 0;
            // Find the comma separating the name and category
            while(line[i]!=',') {
                i++;
            }
            i = i+4;
            // Skip ", " after the name
            // Assign category ID based on category character
            switch (line[i]) {
                case 'a': {
                    firstDigit = 100;
                    id = firstDigit + Appetizers;
                    Appetizers++;
                } break;
                case 'm': {
                    firstDigit = 200;
                    id = firstDigit + Main_Dishes;
                    Main_Dishes++;
                } break;
                case 'd': {
                    firstDigit = 300;
                    id = firstDigit + Desserts;
                    Desserts++;
                } break;
                case 'b': {
                    firstDigit = 400;
                    id = firstDigit + Beverages;
                    Beverages++;
                } break;
                default: firstDigit = 0; // Fallback case if not matched
            }
            // Append the ID to the line and write it to the destination file
            newFile<<line<<". "<<id<<endl;
        }

    }

    newFile.close();
    MyFile.close();

}

// Function to Get a Menu Item by ID

// This function takes an unsigned short ID as input and searches
// through all categories in the menu. It uses a temporary MenuItem object
// with the provided ID for comparison. If a matching item is found
// in any category, a pointer to that item is returned. Otherwise,
// the function returns nullptr.


MenuItemPtr Menu::getItem(unsigned short id) {

    MenuItemPtr tempItem = new MenuItem(id, "s", 0.1, 'V', 'M', {});

    for (int i = 0; i < menuSize; ++i) {

        MenuItemPtr item = categories[i]->contains(*tempItem);
        if (item!= nullptr) {
            delete tempItem; // Delete the temporary item since a match is found
            return item;
        }
    }
    delete tempItem; // Delete the temporary item if no match is found
    return nullptr;
}

// Function to Modify a Menu Item

// This function takes a const reference to a MenuItem object as input.
// It first removes the item with the same ID from the menu using the
// remove_Menu_Item function. Then, it adds the provided MenuItem object
// to the menu using the add_MenuItem function, effectively modifying
// the item details.

void Menu::modifyMenuItem(const MenuItem& item){
    remove_Menu_Item(item.getId());
    add_MenuItem(item);
}

// Function to Add a Menu Item**

// This function takes a const reference to a MenuItem object as input.
// It calculates the category index based on the item's ID
// Then, it inserts the item into the corresponding category's
// linked list using the insertSorted function (assuming sorted insertion).
// The function also attempts to open a file named "modified.txt" in append mode
// and writes the item details to the file. If the file cannot be opened,

void Menu::add_MenuItem(const MenuItem& item) {
    // Calculate the category index based on the item's ID
    int index = item.getId()/100;
    // Insert the item into the corresponding category's linked list using insertSorted
    categories[index]->insertSorted(item);
    // Open "modified.txt" for appending
    ofstream file("modified_menuItems.txt", ios::app);
    // Error check: handle the case where the file cannot be opened
    if (!file.is_open()) {
        std::cerr << "Error opening file" << endl;
        return;
    }
    // Write item details to the file in a comma-separated format
    file << item.getName() << ", " << item.getType()<<", "<<item.getCategory() << ", "<<item.getPrice()<<", ";
    //file << item.getIngredients().size() << " ";
    for (const auto& ingredient : item.getIngredients()) {
        file << ingredient << ", ";
    }
    file << item.getId()<<endl;
    file.close();
}


void Menu::remove_Menu_Item(unsigned short itemId) {
    // Find the menu item with the matching ID
    MenuItemPtr temp = getItem( itemId);
    // Calculate the category index based on the item's ID
    int index = itemId/100;
    // Remove the item from the corresponding category's linked list
    categories[index]->removeObj(*temp);
    // Open "modified.txt" for reading and a temporary file "temp.txt" for writing
    ifstream inFile("modified_menuItems.txt");  // Open the original file for reading
    ofstream outFile("temp.txt");  // Open a temporary file for writing
    string line;
    // Error check: handle the case where either file cannot be opened
    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    while (getline(inFile, line)) {
        // Assuming ID is always the last element in the row and is separated by a space
        size_t lastSpace = line.rfind(' ');
        if (lastSpace != std::string::npos) {
            string idStr = line.substr(lastSpace + 1);
            int currentId = std::stoi(idStr);
            // If the line's ID doesn't match the item to be removed, write it to the temporary file
            if (currentId != itemId) {
                outFile << line << std::endl;
            }
        }

    }
    // Close both files
    inFile.close();
    outFile.close();

    // Remove the original file and rename the temporary file to the original file name
    remove("modified_menuItems.txt");
    rename("temp.txt", "modified_menuItems.txt");

}



void Menu::displayMenu(ostream& out) {
    // Loop through each category in the menu
    for(int i = 0 ;i < menuSize; i++)
        // Call the display function of the current category to print its items
        categories[i]->display(out);
    // Add a newline character after each category's items
        out<<"/n";
}


void Menu::displaySpecialOffer(ostream& out) {
    // Print a header for the special offer section
     out<<"Special Offer:"<<'\n';
    // Loop through all special offer slots (twice the menu size)
    for(int i =0 ; i < menuSize * 2; i++)
        out<<"The items with the special offer are " << *getItem(specialOffer[i].id) << "     "<<'\n';
}

void Menu::displayVeganVegeterian(ostream& out) {
    // Loop through each category in the menu
    for (int i = 0; i < menuSize; ++i) {
        cout<<"line 378\n";
        //cout<<categories[0]->getSize();
        // Loop through each item in the current category
        for(int j = 0; j < categories[i]->getSize(); j++) {
            // Check if the item's type is not 'O'

            if (categories[i]->get(j)->getType() == 'o')
                continue;
            // If the item is vegan/vegetarian, add its ID to the temporary veganVegetarianCat for the current category
            veganVegetarianCat[i]->insertSorted(categories[i]->get(j)->getId());
        }
        }
    // Loop through each category again
    for (int i = 0; i < menuSize; ++i) {
        // Loop through each item ID in the temporary veganVegetarianCat for the current category
        for (int j = 0; j < veganVegetarianCat[i]->getSize(); ++j) {
            out << *getItem(*veganVegetarianCat[i]->get(j))<<"\n";
            }
        // Delete the temporary veganVegetarianCat for the current category after use
        delete veganVegetarianCat[i];
        }


}



void Menu::setOffer() {
    // Temporary pointer for retrieved menu items
    MenuItemPtr temp = NULL;
    int categoryNb= -1;
    unsigned short idd = 1;
    for(int i = 0 ; i < menuSize*2; i++) {
        categoryNb = (i / 2) + 1; //here it increments category nb every 2 iterations
        do {
            //cout<<"entered the do while \n";
            temp = getItem(getRandomId(categoryNb));
            //cout<<temp;


        } while(temp == NULL || temp->getId() == idd);
        specialOffer[i].id = temp->getId(); //here we check if the id is in the list

        //cout<<"got out of the do while";
        idd = temp->getId();
        getItem(specialOffer[i].id)->setPrice(getItem(specialOffer[i].id)->getPrice()*0.7);
        specialOffer[i].quantity = rand() % 8 + 3; // here we generate a random nb between 0 and 7 then add 3 to it
    }
}

int Menu::getRandomId(int categoryNb) {
    // Generate a random number within the range specific to the category
    switch (categoryNb) {
        case 1:
            return (rand() % 100) + 100; // Random IDs between 100 and 199
        case 2:
            return (rand() % 100) + 200; // Random IDs between 200 and 299
        case 3:
            return (rand() % 100) + 300; // Random IDs between 300 and 399
        case 4:
            return (rand() % 100) + 400; // Random IDs between 400 and 499
        default:
            return -1;
    }

}


void Menu::order_item(int itemId) {
    // Find the menu item with the matching ID
    MenuItemPtr ItemPtr = getItem(itemId);
    // Check if the item was found
    if(ItemPtr == nullptr) {
        cout<<"Item is not in the list. Try again. /n";
        return;
    }
    // Loop through all special offer slots
    for ( int i =0 ; i < menuSize*2;i++) {
        // Check if the current special offer slot has the matching item ID
        if(specialOffer[i].id == itemId) {
            // Decrement the quantity of the item in the special offer
            specialOffer[i].quantity--;

            if(specialOffer[i].quantity == 0) {
                for (int j =0 ; j < menuSize*2; j++) {
                    getItem(specialOffer[j].id)->setPrice(getItem(specialOffer[j].id)->getPrice()/0.7);
                    // remove the 30% discount from the offered items
                    // before setting a new offer
                }
                setOffer();
            }
        }
    }


}




