//
//  Max heap implementation
//  Assignment 5
//  cmpt225
//
//  Created by Alexander Lo

#pragma once
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <class T>
class Heap {
public:
    // constructor; creates an array of size "arrSize"
    Heap(int arrsize);
    //copy constructor
    Heap(const Heap &hp);
    //destructor
    ~Heap();
    // overloaded = operator that creates a deep copy
    Heap & operator=(const Heap &hp);
    // inserts value in heap
    void insert(T value);
    // removes and returns root
    T remove();
    // returns root
    T peek() const;
    // returns a heap object that contains values of the calling object
    // and heap reference parameter. The size of returned heap should be
    // the sum of calling object and reference parameter
    Heap merge(const Heap &hp) const;
    // returns number of items stored in heap
    int size() const;
    
    void print();
private:
    // size of array
    int arraySize;
    // array to store values
    T *arr;
    // number of items in heap
    int heapSize;
    // deep copy helper
    void copyHeap(const Heap &);
    // heapify for insertion using bubble up approach
    void heapifyInsert(int index);
    // heapify for removal using bubble down approach
    void heapifyRemove(int index);
};

/*/////////////////////////////// part 2 ///////////////////////////////*/

// returns smallest m numbers in array with the use of a max heap
template <class T>
vector <T> smallestm(vector<T> values, int m) {
    vector<T> smallest(m);
    Heap<T> heapValues(int(values.size()));
    for(int i = 0; i < m; i++) {
        heapValues.insert(values[i]);
    }
    for(int i = m; i < values.size(); i++) {
        if(values[i] < heapValues.peek()) {
            heapValues.remove();
            heapValues.insert(values[i]);
        }
    }
    for(int i = m-1; i >= 0; i--) {
        smallest[i] = heapValues.remove();
    }
    return smallest;
}

/*//////////////////////////////// public ////////////////////////////////*/

// creates a heap of size "size"
template <class T>
Heap<T>::Heap(int size) {
    arr = new T[size];
    arraySize = size;
    heapSize = 0;
}

// calls deep copy helper
template <class T>
Heap<T>::Heap(const Heap &hp) {
    copyHeap(hp);
}

// calls deep copy helper
template <class T>
Heap<T> & Heap<T>::operator=(const Heap &hp) {
    if(this != &hp) {
        delete [] arr;
        copyHeap(hp);
    }
    return *this;
}

// destructor
template <class T>
Heap<T>::~Heap() {
    delete [] arr;
    arr = nullptr;
}

// insert value in heap
template <class T>
void Heap<T>::insert(T value) {
    if(heapSize == arraySize) { // throw error if heap is full
        throw std::runtime_error("Heap is full");
    }
    arr[heapSize] = value; // -1 since array starts at element 0
    heapifyInsert(heapSize);
    heapSize++; // increase size of heap
}

// removes and returns root
template <class T>
T Heap<T>::remove() {
    if(heapSize == 0) { // throw error if heap is empty
        throw std::runtime_error("Heap is empty");
    }
    T rootRemoved = arr[0]; // get root to be removed
    T lastElement = arr[heapSize - 1]; // last element of heap
    arr[0] = lastElement; // replace root
    heapSize--;
    heapifyRemove(0);
    return rootRemoved;
}

// returns a heap object that contains values of the calling object
// and heap reference parameter. The size of returned heap should be
// the sum of calling object and reference parameter
template <class T>
Heap<T> Heap<T>::merge(const Heap &hp) const {
    Heap merged(heapSize + hp.heapSize);
    for(int i = 0; i < heapSize; i++) {
        merged.insert(arr[i]);
    }
    for(int i = 0; i < hp.heapSize; i++) {
        merged.insert(hp.arr[i]);
    }
    return merged;
}

// returns number of items in heap
template <class T>
int Heap<T>::size() const {
    return heapSize;
}

// returns root
template <class T>
T Heap<T>::peek() const {
    if(heapSize == 0) {
        throw std::runtime_error("Heap is empty");
    }
    return arr[0];
}
/*/////////////////////////////// private ///////////////////////////////*/

// heapify for root removal using bubble down approach
template <class T>
void Heap<T>::heapifyRemove(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    // if left child is larger than root
    if (left < heapSize && arr[left] > arr[largest])
        largest = left;
    // if right child is larger than largest so far
    if (right < heapSize && arr[right] > arr[largest])
        largest = right;
    // if largest is not root
    if (largest != index) {
        T temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        // recursively heapify
        heapifyRemove(largest);
    }
}

// heapify for insertion using bubble up approach
template <class T>
void Heap<T>::heapifyInsert(int index) {
    int parent = (index - 1) / 2;
    if(index > 0 && arr[index] > arr[parent]) {
        T temp = arr[index];
        arr[index] = arr[parent];
        arr[parent] = temp;
        heapifyInsert(parent);
    }
}

// deep copy helper
template <class T>
void Heap<T>::copyHeap(const Heap &hp) {
    arraySize = hp.arraySize;
    heapSize = hp.heapSize;
    arr = new T[hp.arraySize];
    for(int i = 0; i < heapSize; i++) {
        arr[i] = hp.arr[i];
    }
}

// print heap
template <class T>
void Heap<T>::print() {
    for(int i = 0; i < heapSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
