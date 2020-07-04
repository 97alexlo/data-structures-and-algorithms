#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST abc;
    abc.insert(10);
    abc.insert(8);
    abc.insert(7);
//    abc.insert(9);
    abc.insert(4);
//    abc.insert(3);
//    abc.insert(5);
//    abc.insert(20);
//    abc.insert(15);
//    abc.insert(25);
//    abc.insert(23);
//    abc.print();
    cout << abc.height() << endl;
    return 0;
}
