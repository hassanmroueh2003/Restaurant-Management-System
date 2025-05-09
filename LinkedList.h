/*-- LinkedList.h -----------------------------------------------------------

This header file defines the LinkedList data structure for managing linked lists.
Basic operations are:
No-arg Constructor: Constructs an empty LinkedList object.
Destructor: Destroys a LinkedList object, freeing memory.
Copy constructor: Constructs a copy of a LinkedList object.
isEmpty: Checks if the list is empty.
getSize: Retrieves the size of the list.
insertAtPosition: Inserts data at a specified position in the list.
removeAtPosition: Removes the node at a given position from the list.
insertSorted: Inserts data into the list in sorted order.
countOccurences: Counts the occurrences of a given item in the list.
removeObj: Removes all occurrences of a given item from the list.
contains: Checks if the list contains a given item.
get: Retrieves the item at a specified position in the list.
display: Outputs the contents of the list.
<< : Output operator overload for displaying the list.
-------------------------------------------------------------------------*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;
template <typename ElementType>
class LinkedList {
private:
    class Node {
    public:
        ElementType data;
        Node* next;
        Node(const ElementType& data) : data(data), next(nullptr) {}
        /*---------------------------------------------------------------------
        Precondition:  Parameter data of type ElementType.

        Postcondition: Initializes a Node with the given data and nullptr
                       as the next pointer.
        ---------------------------------------------------------------------*/

    };
    typedef Node* NodePtr;
    NodePtr myFirst;
    unsigned size;

public:
    LinkedList() : myFirst(nullptr), size(0) {}
    /*---------------------------------------------------------------------
    Precondition:  None.

    Postcondition: Initializes an empty LinkedList object.
    ---------------------------------------------------------------------*/

    ~LinkedList() {
        while (myFirst != nullptr) {
            NodePtr temp = myFirst;
            myFirst = myFirst->next;
            delete temp;
        }
    }
    /*---------------------------------------------------------------------
    Precondition:  None.

    Postcondition: Destroys the LinkedList object, deallocating all
                   dynamically allocated memory.
    ---------------------------------------------------------------------*/

    LinkedList(const LinkedList& copy) {
        size = copy.size;
        if (!this->empty()) {
            myFirst = new Node(copy.myFirst->value);
            NodePtr temp = myFirst;
            NodePtr temp2 = copy.myFirst;
            for (int i = 0; i < size - 1; i++) {
                temp->next = new Node(temp2->next->value);
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
    }

    /*---------------------------------------------------------------------
    Precondition:  Reference to a LinkedList object.

    Postcondition: Initializes a new LinkedList object as a deep copy of
                   the given LinkedList object.
    ---------------------------------------------------------------------*/


    unsigned getSize() const {
        return size;
    }
    /*---------------------------------------------------------------------
    Precondition:  None.

    Postcondition: Returns the size of the LinkedList.
    ---------------------------------------------------------------------*/

    bool empty() const {
        return size == 0;
    }
    /*---------------------------------------------------------------------
    Precondition:  None.

    Postcondition: Returns true if the LinkedList is empty, false otherwise.
    ---------------------------------------------------------------------*/

    void insertAtPosition(unsigned position, const ElementType& data) {
        if (position > size){
            cerr << "Invalid position" << endl;
            return;
        }
        NodePtr newNode = new Node(data);
        if (position == 0) {
            newNode->next = myFirst;
            myFirst = newNode;
        } else {
            NodePtr temp = myFirst;
            for (unsigned i = 0; i < position - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }
    /*---------------------------------------------------------------------
     Precondition:  Position to insert and data to insert.

     Postcondition: Inserts a new Node with the given data at the specified
                    position in the LinkedList.
     ---------------------------------------------------------------------*/

    void removeAtPosition(unsigned position) {
        if (myFirst == nullptr) {
            cerr << "List is empty" << endl;
            return;
        }
        if (position >= size) {
            cerr << "Invalid position" << endl;
            return;
        }

        if (position == 0) {
            NodePtr temp = myFirst;
            myFirst = myFirst->next;
            delete temp;
        } else {
            Node* temp = myFirst;
            for (unsigned i = 0; i < position - 1; i++) {
                temp = temp->next;
            }
            NodePtr temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
        size--;
    }
    /*---------------------------------------------------------------------
    Precondition:  Position of the Node to remove.

    Postcondition: Removes the Node at the specified position in the
                   LinkedList.
    ---------------------------------------------------------------------*/

    void insertSorted(const ElementType& data) {
        NodePtr newNode = new Node(data);
        if (myFirst == nullptr || myFirst->data >= data) {
            newNode->next = myFirst;
            myFirst = newNode;
        } else {
            NodePtr temp = myFirst;
            while (temp->next != nullptr && !(temp->next->data >= data)) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;

        }
        size++;
    }
    /*---------------------------------------------------------------------
    Precondition:  Data to insert.

    Postcondition: Inserts a new Node with the given data into the
                   LinkedList in sorted order.
    ---------------------------------------------------------------------*/

    unsigned countOccurences(const ElementType &item) {
        int count = 0;
        NodePtr temp = myFirst;
        while (temp != nullptr) {
            if (temp->data == item) {
                count++;
            }
            temp = temp->next;
        }
        return count;
        }
    /*---------------------------------------------------------------------
    Precondition:  Data to count occurrences of.

    Postcondition: Returns the number of occurrences of the given data
                   in the LinkedList.
    ---------------------------------------------------------------------*/

    void removeObj(const ElementType& data){
            Node* temp = myFirst;
            Node* prev = nullptr;

            while (temp != nullptr) {
                if (temp->data == data) {
                    if (prev) {
                        prev->next = temp->next;
                    } else {
                        myFirst = temp->next;
                    }
                    Node* toDelete = temp;
                    temp = temp->next;
                    delete toDelete;
                    size--;
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
    }

    /*---------------------------------------------------------------------
    Precondition:  Data to remove.

    Postcondition: Removes all occurrences of the given data from the
                   LinkedList.
    ---------------------------------------------------------------------*/

    ElementType * contains(ElementType& data) const {
        NodePtr temp = myFirst;
        while (temp != nullptr) {
            if (temp->data == data) {
                return &(temp->data);
            }
            temp = temp->next;
        }
        return nullptr;

    }
    /*---------------------------------------------------------------------
    Precondition:  Data to search for.

    Postcondition: Returns a pointer to the first occurrence of the given
                   data in the LinkedList, or nullptr if not found.
    ---------------------------------------------------------------------*/



    ElementType* get(unsigned pos) const {
        if (pos >= size) {
            cerr << "Invalid position" << endl;
            return nullptr;
        }
        NodePtr temp = myFirst;
        for (unsigned i = 0; i < pos; i++) {
            temp = temp->next;
        }
        return &(temp->data);
    }
    /*---------------------------------------------------------------------
    Precondition:  Position of the data to retrieve.

    Postcondition: Returns a pointer to the data at the specified position
                   in the LinkedList.
    ---------------------------------------------------------------------*/

    void display(ostream& out) const {
        NodePtr temp = myFirst;
        while (temp != nullptr) {
            out << temp->data << endl;
            temp = temp->next;
        }
    }
    /*---------------------------------------------------------------------
    Precondition:  Output stream to display the LinkedList.

    Postcondition: Displays the contents of the LinkedList on the output
                   stream.
    ---------------------------------------------------------------------*/

    friend ostream& operator<<(ostream& out, const LinkedList& list) {
        list.display(out);
        return out;
    }
    /*---------------------------------------------------------------------
    Precondition:  Output stream and a LinkedList object.

    Postcondition: Overloads the << operator to display the contents of
                   the LinkedList on the output stream.
    ---------------------------------------------------------------------*/

};

#endif // LINKED_LIST_H


