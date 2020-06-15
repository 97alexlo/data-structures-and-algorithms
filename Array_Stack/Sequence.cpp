//  Sequence.h
//  cmpt225 Assignment 1
//  Created by Alexander Lo

#include "Sequence.h"
#include <cmath>

using std::endl;
using std::cout;
using std::sort;

// makes an empty array of size 0
Sequence::Sequence() throw(bad_alloc) {
    arraySize = 0;
    maxSize = 2;
    array = new double[maxSize];
}

// constructor thatmakes a deep copy (literal copy) of the sequence
Sequence::Sequence(const Sequence & sq) throw(bad_alloc) {
    copySequence(sq);
}

// makes a deep copy (literal copy) of the sequence
// through with overloaded operator
Sequence & Sequence::operator=(const Sequence & sq) throw(bad_alloc) {
    // it both are not the same objects, make a copy
    if(this != &sq) {
        delete [] array;
        copySequence(sq);
    }
    // if they are the same object, return the object
    return *this;
}

// destructor
Sequence::~Sequence() {
    delete [] array;
    array = nullptr;
}

// inserts a value at the end of the sequence
// if array size is too small, create a new sequence 2 times longer
// and inserts values
void Sequence::insert(double value) {
    if(arraySize == maxSize) {
        double tempArray[arraySize];
        maxSize = 2 * maxSize;
        for(int i = 0; i < arraySize; i++) {
            tempArray[i] = array[i];
        }
        delete [] array;
        array = new double[maxSize];
        for(int i = 0; i < arraySize; i++) {
            array[i] = tempArray[i];
        }
    }
    array[arraySize++] = value;
}

// inserts an array at the end of the sequence
// if sequence is to short, creata a new sequence that exactly
// fits all numbers
void Sequence::insert(const double values[], const int size) {
    if(maxSize < (arraySize + size)) {
        double tempArray[arraySize];
        for(int i = 0; i < arraySize; i++) {
            tempArray[i] = array[i];
        }
        delete [] array;
        array = new double[arraySize+size];
        for(int i = 0; i < arraySize; i++) {
            array[i] = tempArray[i];
        }
    }
    for(int i = 0; i < size; i++) {
        array[arraySize+i] = values[i];
    }
    arraySize = arraySize + size;
}

// print sequence
//void Sequence::print() const {
//    for(int i = arraySize-1; i >= 0; i--) {
//        cout << array[i] << endl;
//    }
//    cout << endl;
//}

// returns the number of matches of the parameter in the sequence
int Sequence::find(const double numToMatch) const {
    int count = 0;
    for(int i = 0; i < arraySize; i++) {
        if(array[i] == numToMatch) {
            count++;
        }
    }
    return count;
}

// returns size of the sequence
int Sequence::size() const {
    return arraySize;
}

// returns sum of all values in the sequence
double Sequence::sum() const {
    double sum = 0;
    for(int i = 0; i < arraySize; i++) {
        sum += array[i];
    }
    return sum;
}

// returns the mean of values in the sequence
double Sequence::mean() const {
    double sum = 0;
    
    for(int i = 0; i < arraySize; i++) {
        sum += array[i];
    }
    return sum / arraySize;
}

// sorts the sequence and returns the median
double Sequence::median() const {
    sort(array, array+arraySize);
    if (arraySize % 2 != 0) {
        return array[arraySize / 2];
    }
    return (array[(arraySize - 1) / 2] + array[arraySize / 2]) / 2.0;
}

// returns standard deviation of values in the sequence
double Sequence::stddev() const {
    double mean = 0;
    double sum = 0;
    for(int i = 0; i < arraySize; i++) {
        sum += array[i];
    }
    mean = sum / arraySize;
    sum = 0;
    for(int i = 0; i < arraySize; i++) {
        sum += pow((array[i] - mean), 2);
    }
    return sqrt(sum / arraySize);
}
// returns a new sequence object that concatenates the calling
// object followed by the sequence paramter
Sequence Sequence::concatenate(const Sequence &sq) {
    Sequence sqNew;
    for(int i = 0; i < arraySize; i++) {
        sqNew.insert(array[i]);
    }
    for(int i = 0; i < sq.arraySize; i++) {
        sqNew.insert(sq.array[i]);
    }
    return sqNew;
}

// copies parameter into calling object
void Sequence::copySequence(const Sequence &sq) {
    arraySize = sq.arraySize;
    maxSize = sq.maxSize;
    array = new double[maxSize];
    for(int i = 0; i < arraySize; i++) {
        array[i] = sq.array[i];
    }
}
