#include "MenuItem.h"

// Constructor definition
MenuItem::MenuItem(unsigned short id, string name, float price, char type, char category, vector<string> ingredients)
        : id(id), name(name), price(price), type(type), category(category), ingredients(ingredients) {}

// Getters
unsigned short MenuItem::getId() const {
    return id;
}

string MenuItem::getName() const {
    return name;
}

float MenuItem::getPrice() const {
    return price;
}

char MenuItem::getType() const {
    return type;
}

char MenuItem::getCategory() const {
    return category;
}

vector<string> MenuItem::getIngredients() const {

    return ingredients;
}

// Setters
void MenuItem::setId(unsigned short id) {
    // Check if the id is within the valid range
    if( id >= 100 && id < 500)
        this->id = id;
    else
        printf("Error: ID outside of range");
}

void MenuItem::setName(string &name) {
    if (!name.empty()) { // Ensure name is not empty
        this->name = name;
    }
    this->name = name;
}

void MenuItem::setPrice(float price) {
    // Ensure price is non-negative
    if (price >= 0.0) {
        this->price = price;
    }
}

void MenuItem::setType(char type) {
    // Ensure type is valid
    if (type == 'v' || type == 'g' || type == 'o')
        this->type = type;
}

void MenuItem::setCategory(char category) {
    // Ensure category is valid
    if (category == 'a' || category == 'm' || category == 'd' || category == 'b')

        this->category = category;
}

void MenuItem::setIngredients(vector<string> ingredients) {
    // Ensure ingredients vector is not empty
    if (!ingredients.empty()) {
        this->ingredients = ingredients;
    }
}

void MenuItem::setMenuItem(unsigned short id, string name, double price, char type, char category,
                               vector<string> ingredients) {
        // Set all attributes of MenuItem
        setId(id);
        setName(name);
        setPrice(static_cast<float>(price));
        setType(type);
        setCategory(category);
        setIngredients(ingredients);
}

// Operator Overloads
MenuItem &MenuItem::operator=(const MenuItem &menuItem) {
        if (this != &menuItem) {
            // Copy all attributes
            id = menuItem.id;
            name = menuItem.name;
            price = menuItem.price;
            type = menuItem.type;
            category = menuItem.category;
            ingredients = menuItem.ingredients;
        }
        return *this;
}



// Equality operator that compares id
bool MenuItem::operator==(const MenuItem &righthandside) const {
    return (id == righthandside.id);
}
// Greater than or equal operator that compares prices
bool MenuItem::operator>=(const MenuItem &righthandside) const {
        return (price >= righthandside.price);
}
// Output stream operator to print MenuItem details
ostream& operator<<(ostream &out, const MenuItem &menuItem) {
    out << "ID: " << menuItem.getId()
        <<endl<<" Name: " << menuItem.getName()
        <<endl<<"Price: $" << menuItem.getPrice()
        <<endl<< "Type: " << menuItem.getType()
        <<endl<<"Category: " << menuItem.getCategory()
        <<endl<< "Ingredients: ";
    for (const auto &ingredient: menuItem.getIngredients()) {
        out << ingredient << ", ";
    }
    return out;
}
