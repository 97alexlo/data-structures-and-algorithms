//
//  main.cpp
//  Assignment3
//
//  Created by Alex Lo on 2020-06-24.
//  Copyright © 2020 Alex Lo. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

#include "cmpt225sort.h"

using namespace std;
template <class T>
T* readFile(string infile, int & n);
void basicTest();

int main() {
    
    double arr[6] = {6,5,4,3,2,1};
    cout << "insertion sort test" << endl;
    cout << "# of barometer operations " << insertionsort(arr, 6) << endl;
    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    int arr2[6] = {1,2,3,4,5,6};
    cout << endl << "quicksort test" << endl;
    cout << "# of barometer operations " << quicksort(arr2, 6) << endl;
    for(int i = 0; i < 6; i++) {
        cout << arr2[i] << " ";
    }
    int arr3[6] = {6,5,4,3,2,1};
    cout << endl << "mergesort test" << endl;
    cout << "# of barometer operations " << mergesort(arr3, 6) << endl;
    for(int i = 0; i < 6; i++) {
        cout << arr3[i] << " ";
    }
    int arr4[6] = {6,3,2,4,5,1};
    cout << endl << "shellsort test" << endl;
    cout << "# of barometer operations " << shellsort(arr4, 6) << endl;
    for(int i = 0; i < 6; i++) {
        cout << arr4[i] << " ";
    }
    
    basicTest();
    return 0;
}

void basicTest()
{
    int n = 0;
    int* arr1 = readFile<int>("a3test1.txt", n);
    cout << "insertion sort comparisons = " << insertionsort<int>(arr1, n) << endl;
    for(int i = 0;i <n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    float* arr2 = readFile<float>("a3test2.txt", n);
    cout << "quicksort comparisons = " << quicksort<float>(arr2, n) << endl;
    for(int i = 0;i <n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    string* arr3 = readFile<string>("a3test3.txt", n);
    cout << "mergesort comparisons = " << mergesort<string>(arr3, n) << endl;
    for(int i = 0;i <n; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    cout << "shell sort comparisons = " << shellsort<string>(arr3, n) << endl;
    for(int i = 0;i <n; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
}

// PARAM: infile = name of the file to be opened
//        n = the size of the result array
// PRE: the file contains values separated by white space
// POST: returns an array containing the contents of infile
template <class T>
T* readFile(string infile, int & n)
{
    T* result;
    T next;
    n = 0;
 
    ifstream ist(infile.c_str()); // open file
    // Check if file opened correctly
    if (ist.fail()) {
        throw runtime_error(infile + " not found");
    }
 
    // Find file size
    while (ist >> next) {
        n++;
    }
 
    // Read file into array
    ist.close();
    ist.open(infile.c_str());
    result = new T[n];
    for (int i = 0; i < n; ++i) {
        ist >> result[i];
    }
 
    ist.close();
    return result;
}
