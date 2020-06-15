//
//  main.cpp
//  Exercise2
//
//  Created by Alex Lo on 2020-05-21.
//  Copyright © 2020 Alex Lo. All rights reserved.
//

#include <iostream>
#include "Exercise2.h"

using namespace std;

int main() {
    int n = 8;
    int arr[] = {1,2,3,4,3,2,1,4};
    int returned = 0;
    int matchNum = 3;
    
    cout << "original array, size = " << sizeof(arr) / sizeof(arr[0]) << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl << "remove all " << matchNum << endl;
    
    returned = remove(arr, n, matchNum);
    
    cout << endl << "new array, size = " << n << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl << "numbers removed: " << returned << endl;
    return 0;
}
