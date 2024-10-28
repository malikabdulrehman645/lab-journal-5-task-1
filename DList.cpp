// DList.cpp
#include "DList.h"
#include <iostream>
using namespace std;

// Constructor
DList::DList() : head(nullptr) {}

// Checks if the list is empty
bool DList::emptyList() {
    return head == nullptr;
}

// Inserts a new node with value `newV` after the node containing value `oldV`
void DList::insert_after(int oldV, int newV) {
    Node* temp = head;

    // Traverse the list to find the node with value `oldV`
    while (temp && temp->data != oldV) {
        temp = temp->next;
    }

    // If the node with `oldV` is found
    if (temp) {
        Node* newNode = new Node();
        newNode->data = newV;         // Set data value
        newNode->next = temp->next;
        newNode->prev = temp;
        
        if (temp->next) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

// Deletes the node containing the specified value
void DList::deleteNode(int value) {
    Node* temp = head;

    // Find the node with the specified value
    while (temp && temp->data != value) {
        temp = temp->next;
    }

    // If the node is found
    if (temp) {
        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        
        if (temp->next) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }
}

// Inserts a new node at the start of the list
void DList::insert_begin(int value) {
    Node* newNode = new Node();
    newNode->data = value;  // Set data value

    newNode->next = head;
    if (head) {
        head->prev = newNode;
    }
    head = newNode;
}

// Inserts a new node at the end of the list
void DList::insert_end(int value) {
    Node* newNode = new Node();
    newNode->data = value;  // Set data value

    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Displays the values stored in the list starting from head
void DList::traverse() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Reverses the doubly linked list
void DList::reverse() {
    Node* current = head;
    Node* temp = nullptr;

    // Swap next and prev for all nodes of the doubly linked list
    while (current != nullptr) {
        // Swap the next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node in the original order
        current = current->prev; // current->prev is the next node in original order
    }

    // Update head to the new first node
    if (temp != nullptr) {
        head = temp->prev;
    }
}

// Displays the contents of alternate nodes of the doubly linked list
void DList::displayAlternateNodes() {
    Node* current = head;
    bool alternate = true; // Flag to track alternate nodes

    while (current != nullptr) {
        if (alternate) {
            cout << current->data << " "; // Display the current node's data
        }
        alternate = !alternate; // Toggle the alternate flag
        current = current->next; // Move to the next node
    }
    cout << endl; // For better output formatting
}