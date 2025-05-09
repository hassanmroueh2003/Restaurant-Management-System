# 🍽️ Restaurant Management System

An academic C++ project developed by **Hassan Mroueh** and **Ahmad El Hage** as part of a data structures coursework.  
The system simulates a basic restaurant management interface with **Admin** and **Client** roles, offering features such as menu management, cart operations, and bill generation using custom LinkedLists and object-oriented design.

---

## 🚀 Features

### 👨‍🍳 Admin
- Secure login with predefined credentials
- Add, modify, or delete menu items
- View vegetarian/vegan and special offer items
- Display full menu from file

### 👥 Client
- Add/remove items from a shopping cart
- View cart contents and quantities
- Generate and finalize a receipt
- View vegan/vegetarian items and special offers

---

## 🗂️ File Structure

```bash
Restaurant-Management-System/
├── Admin.cpp / Admin.h              # Admin user functionality
├── Client.cpp / Client.h            # Client user functionality
├── Users.cpp / Users.h              # Abstract base class for user roles
├── Menu.cpp / Menu.h                # Menu class for item management
├── MenuItem.cpp / MenuItem.h        # Class for individual menu items
├── LinkedList.h                     # Custom template-based linked list
├── main.cpp                         # Main entry point for the CLI app
├── menuItems.txt                    # Source data for menu initialization
└── README.md                        # Project documentation


````markdown
## 🧱 Compilation Instructions

To compile the project:

```bash
g++ -std=c++17 main.cpp Admin.cpp Client.cpp Users.cpp Menu.cpp MenuItem.cpp -o restaurant
````

Then run it:

```bash
./restaurant
```

> **Note:** Make sure `menuItems.txt` is in the same directory.

---

## 📌 Dependencies

* Standard C++17
* Uses only the C++ Standard Library (no external packages)

---

## 👨‍🎓 Authors

* **Hassan Mroueh**
* **Ahmad El Hage**
  *Developed as part of the Data Structures course at the University of Balamand.*
  



