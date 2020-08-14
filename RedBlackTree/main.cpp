//
//  main.cpp
//  RedBlackTree_v2
//
//  Created by Alex Lo on 2020-07-22.
//  Copyright © 2020 Alex Lo. All rights reserved.
//

#include <iostream>
#include "RedBlackTree.h"
#include <string>
using namespace std;
void myTest() ;
void simpleTest();

int main() {
//    simpleTest();
    myTest();
    return 0;
}


void myTest() {
    RedBlackTree<int, string> rbt;
//    rbt.insert("a", "twelve");
//    rbt.insert("c", "five");
//    rbt.insert("b", "ten");
    rbt.insert(5, "five");
    rbt.insert(12, "twelve");
    rbt.insert(7, "seven");
    rbt.insert(13, "thirteen");
    rbt.insert(6, "six");
    rbt.insert(101,"zzz");
    rbt.insert(11, "evelen");
    rbt.remove(13);
    rbt.remove(12);
    rbt.remove(7);
    rbt.remove(6);
    rbt.remove(11);
    rbt.remove(5);
    rbt.remove(101);
//    rbt.print();
//    cout << "root is " << rbt.getRoot()->key << endl;
    cout << "size is " << rbt.size() << endl;
    cout << "search for 12 1 - " << rbt.search(12) << endl;
    cout << "search for 100 0 - " << rbt.search(100) << endl;
    cout << "values who's 5 <= key <= 12 in tree in ascending key order " << endl;
    for(int i = 0; i < rbt.search(12,5).size(); i++) {
        cout << rbt.search(12,5)[i] << " ";
    }
    cout << endl << "all values in tree in ascending key order " << endl;
    for(int i = 0; i < rbt.values().size(); i++) {
        cout << rbt.values()[i] << " ";
    }
    cout << endl << "all keys in tree in ascending key order " << endl;
    for(int i = 0; i < rbt.keys().size(); i++) {
        cout << rbt.keys()[i] << " ";
    }
    cout << endl << endl;
    cout << "copy test" << endl;
    RedBlackTree<int, string> rbt2 = rbt;
//    rbt2.remove("a");
//    rbt2.insert("eve","eleven");
//    rbt2.remove("eve");
    rbt2.remove(13);
    rbt2.remove(12);
    rbt2.remove(7);
    rbt2.remove(6);
    rbt2.remove(11);
    rbt2.remove(5);
    rbt2.remove(101);
//    rbt2.insert(6, "a");
//    rbt2.print();
//    cout << "root is " << rbt2.getRoot()->key << endl;
    cout << "size is " << rbt2.size() << endl;
    cout << "search for 12 1 - " << rbt2.search(12) << endl;
    cout << "search for 100 0 - " << rbt2.search(100) << endl;
    cout << "values who's 5 <= key <= 12 in tree in ascending key order " << endl;
    for(int i = 0; i < rbt2.search(12,5).size(); i++) {
        cout << rbt2.search(12,5)[i] << " ";
    }
    cout << endl << "all values in tree in ascending key order " << endl;
    for(int i = 0; i < rbt2.values().size(); i++) {
        cout << rbt2.values()[i] << " ";
    }
    cout << endl << "all keys in tree in ascending key order " << endl;
    for(int i = 0; i < rbt2.keys().size(); i++) {
        cout << rbt2.keys()[i] << " ";
    }
    cout << endl;
}

void simpleTest()
{
    // Int Tree Tests
    RedBlackTree<int, char> rb1;
    if (rb1.insert(6, 'f')) cout << "inserted 42" << endl;
    rb1.insert(10, 'j');
    rb1.insert(2, 'b');
    RedBlackTree<int, char> rb2(rb1);
    if (rb2.remove(2)) cout << "removed 2" << endl;
    if (rb2.search(6)) cout << "found 6" << endl;
    cout << "search should contain j - ";
    vector<char> v1 = rb2.search(8, 21); //should contain j
    for(int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    cout << "values shoudl contain f j - ";
    for(int i = 0; i < rb2.values().size(); i++) {
        cout << rb2.values()[i] << " ";
    } //should contain {f, j}
    cout << endl;
    cout << "keys should containt 6 10 - ";
    for(int i = 0; i < rb2.keys().size(); i++) {
        cout << rb2.keys()[i] << " ";
    }
    cout << endl;
    cout << "size = " << rb2.size() << endl; //should be 2
    NodeT<int, char>* pRoot = rb2.getRoot(); //BAD design - for our testing only
    cout << "root is " << pRoot->value << endl;
//    rb2.print();
}
