#include "Node.h"
#include "Link_list.h"
#include <iostream>


using namespace std;

int main() {
    LinkedList list1;

   
    list1 + 10;
    list1 + 20;
    list1 + 30;
    list1 + 40;

    cout << "List1: " << list1 << endl;

    
    LinkedList list2 = list1;

    cout << "List2: " << list2 << endl;

    
    list2 += 5;

    cout << "List2 after adding 5 at the beginning: " << list2 << endl;

    
    list2 - 20;

    cout << "List2 after removing 20: " << list2 << endl;

    cout << "List 1 with elem index 3" << endl;
    cout << list1[3] << endl;
    
    if (list1 == list2) {
        cout << "List1 and List2 are equal." << endl;
    }
    else {
        cout << "List1 and List2 are not equal." << endl;
    }

    cout << "List1 elements from index 1 to 3: ";
    list1(1, 3);

    string listString = static_cast<string>(list1);

    cout << "List as string: " << listString << endl;

    return 0;
}
