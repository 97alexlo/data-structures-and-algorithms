//
//  main.cpp
//  Assignment5
//
//  Created by Alex Lo on 2020-07-28.
//  Copyright © 2020 Alex Lo. All rights reserved.
//

#include <iostream>
#include "Heap.h"

using namespace std;

void simpleTest();
void myTest();
void part2();

int main() {
//    simpleTest();
    myTest();
    cout << endl << "part 2 test" << endl;
    part2();
    return 0;
}

void part2() {
    vector<int> abc;
    abc.push_back(5);
    abc.push_back(10);
    abc.push_back(3);
    abc.push_back(10);
    abc.push_back(10);
    for(int i = 0; i < abc.size(); i++) {
        cout << abc[i] << " ";
    }
    cout << endl;
    vector<int> result = smallestm(abc, 5);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}
void myTest() {
    Heap<string> abc(6);
    try {
        abc.peek();
    }
    catch(exception &e) {
        cout << e.what() << endl;
    }
    abc.insert("a");
    abc.insert("bcs");
    abc.insert("zz");
    abc.insert("fd");
    abc.insert("e");
    cout << "root removed is " << abc.remove() << endl;
    cout << "root is " << abc.peek() << endl;
    cout << "root removed is " << abc.remove() << endl;
    cout << "root is " << abc.peek() << endl;
    cout << "root removed is " << abc.remove() << endl;
    cout << "root is " << abc.peek() << endl;
    cout << "root removed is " << abc.remove() << endl;
    cout << "root is " << abc.peek() << endl;
    cout << "root removed is " << abc.remove() << endl;
    try {
        abc.remove();
    }
    catch(exception &e) {
        cout << e.what() << endl;
    }
    abc.print();
    cout << "heap size is " << abc.size() << endl;
    try {
        cout << "root is " << abc.peek() << endl;
    }
    catch(exception &e) {
        cout << e.what() << endl;
    }
    
    cout << endl << "normal heap test - second heap"<< endl;
    Heap<double> abc2(6);
    abc2.insert(6);
    abc2.insert(2);
    abc2.insert(3);
    abc2.insert(5);
    abc2.insert(5);
    abc2.insert(1);
    abc2.print();
    cout << "root removed is " << abc2.remove() << endl;
    abc2.print();
    cout << "heap size is " << abc2.size() << endl;
    cout << "root is " << abc2.peek() << endl;
    
    cout << endl << "normal heap test - third heap"<< endl;
    Heap<double> abc3(3);
    abc3.insert(3);
    abc3.insert(2);
    abc3.insert(7);
    abc3.print();
    cout << "root removed is " << abc3.remove() << endl;
    cout << "heap size is " << abc3.size() << endl;
    cout << "root is " << abc3.peek() << endl;
    
    cout << endl << "merge test"<< endl;
    Heap<double> abc4 = abc2.merge(abc3);
    abc4.print();
    cout << "root removed is " << abc4.remove() << endl;
    abc4.print();
    cout << "heap size is " << abc4.size() << endl;
    cout << "root is " << abc4.peek() << endl;
    
    cout << endl << "copy constructor test" << endl;
    Heap<double> abc5 = abc4;
    abc5.print();
    abc5.insert(100);
    abc5.print();
    cout << "root removed is " << abc5.remove() << endl;
    abc5.print();
    cout << "heap size is " << abc5.size() << endl;
    cout << "root is " << abc5.peek() << endl;
}

void simpleTest()
{
    // Int Heap Tests
    Heap<int> pq1(4);
 
    pq1.insert(3);
    pq1.insert(1);
    pq1.insert(42);
 
    cout << "pq1 root = " << pq1.peek() << endl; //42
    cout << "root removed is 42 - " << pq1.remove();
    cout << "pq1 root = " << pq1.peek() << endl; //3
    cout << "pq1 size = " << pq1.size() << endl; //2
 
    Heap<int> pq2(pq1);
    pq2.insert(13);
    cout << "pq2 size = " << pq2.size() << endl;
    Heap<int> pq3 = pq1.merge(pq2); // should contain duplicates
    cout << "pq3 size = " << pq3.size() << endl; //5
    cout << "pq3 root = " << pq3.peek() << endl; //13
}
