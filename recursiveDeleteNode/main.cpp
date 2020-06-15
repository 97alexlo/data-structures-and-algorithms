//
//  main.cpp
//  Exercise4
//
//  Created by Alex Lo on 2020-06-05.
//  Copyright © 2020 Alex Lo. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main () {
    LinkedList abc;
//    abc.insert(1);
//    abc.insert(2);
//    abc.insert(3);
//    abc.insert(4);
//    abc.insert(3);
//    abc.insert(3);
    abc.insert(3);
    abc.insert(3);
    abc.insert(4);
    abc.insert(5);
    abc.insert(3);
    
    abc.remove(3);
    abc.print();
    return 0;
}
