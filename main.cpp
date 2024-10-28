// main.cpp
#include "DList.h"
#include <iostream>
using namespace std;

int main() {
    DList list;

    // Insert some elements
    list.insert_end(10);
    list.insert_end(20);
    list.insert_end(30);
    list.insert_end(40);
    list.insert_end(50);

    cout << "Original list: ";
    list.traverse();

    // Display alternate nodes
    cout << "Alternate nodes: ";
    list.displayAlternateNodes();

    // Reverse the list
    list.reverse();
    cout << "Reversed list: ";
    list.traverse();

    return 0;
}
