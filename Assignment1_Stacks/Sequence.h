//  Sequence.h
//  Created by Alexander Lo

#pragma once
#include <iostream>

using std::bad_alloc;

class Sequence {
public:
    // default constructor
    Sequence() throw(bad_alloc);
    // deep copy constructor
    Sequence(const Sequence &sq) throw(bad_alloc);
    // overloaded = operator to make a deep copy
    Sequence & operator=(const Sequence &sq) throw(bad_alloc);
    //deconstructor
    ~Sequence();
    // insert a value at the end
    void insert(const double value);
    // insert an array at the end
    void insert(const double values[], const int size);
    // print sequence
//    void print() const;
    // find number of matches of the function parameter in the sequence
    int find(const double numToMatch) const;
    // find sequence length
    int size() const;
    //find sum of all numbers in the sequence
    double sum() const;
    //find mean of sequence
    double mean() const;
    //find median of sequence
    double median() const;
    //find standard deviation of sequence
    double stddev() const;
    // returns a sequence that concatenates the calling sequence
    // object with the parameter sequence object at the end
    Sequence concatenate(const Sequence &sq);
private:
    double *array;
    int arraySize;
    int maxSize;
    // makes a deep copy of the sequence
    void copySequence(const Sequence &sq);
};

