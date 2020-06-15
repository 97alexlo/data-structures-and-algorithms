//
//  main.cpp
//  Assignment2_dequeue
//
//  Created by Alex Lo on 2020-06-03.
//  Copyright © 2020 Alex Lo. All rights reserved.
//

#include <iostream>
#include "Deque.h"

using namespace std;

int main()
{
    Deque<int> abc;
    cout << "insert front 3 2 1" << endl;
    abc.insertFront(1);
    abc.insertFront(2);
    abc.insertFront(3);
    abc.print();
    cout << "insert back 2 3" << endl;
    abc.insertBack(2);
    abc.insertBack(3);
    abc.print();
    cout << "remove front" << endl;
    abc.removeFront();
    abc.print();
    cout << "remove back" << endl;
    abc.removeBack();
    abc.print();
    cout << "size is " << abc.size() << endl;
    Deque<int> second = abc;
    cout << "print second copy of abc" << endl;
    second.print();
    second.removeBack();
    cout << "remove back second" << endl;
    second.print();
    cout << "remove front x2, empty list" << endl;
    second.removeFront();
    second.removeFront();
    second.print();
    cout << "is it empty? " << second.empty() << endl;
    cout << "size: " << second.size() << endl;
    try {
        cout << "peekfront test: " << second.peekFront() << endl;
        cout << "peekback test: " << second.peekBack() << endl;
    }
    catch(std::runtime_error e) {
        cout << "error caught, " << e.what() << endl;
    }
    cout << "testing = operator" << endl;
    Deque<int> abc2;
    abc2 = abc;
    abc2.print();
    cout << "insert front 2, and back 1" << endl;
    abc2.insertBack(1);
    abc2.insertFront(2);
    abc2.print();
    cout << "is it empty? " << abc2.empty() << endl;
    cout << "size: " << abc2.size() << endl;
    cout << "peekfront test: " << abc2.peekFront() << endl;
    cout << "peekback test: " << abc2.peekBack() << endl;
//    Deque<int> dq1;
//    cout << dq1.empty() << " - 1" << endl;
//    dq1.insertFront(42);
//    dq1.insertBack(216);
//    cout << dq1.peekFront() << " - 42" << endl;
//    cout << dq1.peekBack() << " - 216" << endl;
//    cout << dq1.size() << " - 2" << endl;
//
//    Deque<int> dq2(dq1);
//    Deque<int> dq3;
//    dq3 = dq1;
//
//    cout << dq1.removeFront() << " - 42" << endl;
//    cout << dq1.removeBack() << " - 216" << endl;
//
//    cout << dq2.peekFront() << " - 42" << endl;
//    cout << dq2.peekBack() << " - 216" << endl;
//    cout << dq3.peekFront() << " - 42" << endl;
//    cout << dq3.peekBack() << " - 216" << endl;
//    dq3.print();
//    cout << "size " << dq3.size() << endl;
    return 0;
}
