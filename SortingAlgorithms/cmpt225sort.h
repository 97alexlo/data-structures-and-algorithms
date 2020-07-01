// insertionsort, quicksort, mergesort, and shellsort barometer operations
// Created by Alexander Lo on june 27, 2020
// cmpt 225
#pragma once

#include <iostream>

using std::cout;
using std::endl;
    
/* ////////////////// Insertion sort ////////////////// */
// returns number of barometer operations
// takes in array and array size
template <class T>
int insertionsort(T array[], int size) {
    int count = 0;
    if(size < 2) {
        return 0;
    }
    for(int i = 1; i < size; i++) {
        T temp = array[i];
        int pos = i;
        while(pos > 0 && array[pos - 1] > temp) {
            array[pos] = array[pos - 1];
            pos--;
            count++;
        }
        array[pos] = temp;
    }
    return count;
}

/* ////////////////// Quicksort ////////////////// */
// swaps two numbers
template <class T>
void swap(T& num1, T& num2) {
    T temp = num2;
    num2 = num1;
    num1 = temp;
}

// called from quicksortHelper, divides array into small and large values
template <class T>
int partition(T array[], int start, int end, int& count) {
    T pivot = array[end]; // use last value as pivot
    int pIndex = start;
    for(int i = start; i < end; i++) {
        if(array[i] <= pivot) {
            swap(array[i], array[pIndex]);
            pIndex++;
        }
        count++;
    }
    swap(array[pIndex], array[end]);
    return pIndex;
}

// called from quicksort
template <class T>
void quicksortHelper(T array[], int start, int end, int &count) {
    if(start < end) {
        int pIndex = partition(array, start, end, count);
        quicksortHelper(array, start, pIndex - 1, count);
        quicksortHelper(array, pIndex + 1, end, count);
    }
}

// returns number of barometer operations
template <class T>
int quicksort(T array[], int size) {
    int count = 0;
    int start = 0;
    int end = size - 1;
    if(size < 2) {
        return 0;
    }
    quicksortHelper(array, start, end, count);
    return count;
}

/* ////////////////// Merge sort ////////////////// */

// returns minimum of two values
template <class T>
T min(T num1, T num2) {
    if(num1 < num2) {
        return num1;
    }
    else {
        return num2;
    }
}

// sorts and merges two arrays
template <class T>
void merge(T arr[], int left, int mid, int right, int& count)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // create left and right temp arrays
    T L[n1], R[n2];
  
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    // Merge the temp arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        count++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[]
    // if thereare any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        count++;
    }
    // Copy the remaining elements of R[]
    // if thereare any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        count++;
    }
}

// returns number of barometer operations
// takes in array and array size
template <class T>
int mergesort(T array[], int size) {
    if(size < 2) {
         return 0;
     }
    int count = 0;
    for(int currSize = 1; currSize <= size-1; currSize = 2*currSize) {
        for(int left = 0; left < size-1; left += 2*currSize) {
            int mid = min(left + currSize - 1, size - 1);
            int right = min(left + 2*currSize - 1, size - 1);
            merge(array, left, mid, right, count);
        }
    }
    return count;
}

/* ////////////////// Shell sort ////////////////// */
// reference: https://www.geeksforgeeks.org/shellsort/
// returns number of barometer operations
// takes in array and array size
template <class T>
int shellsort(T array[], int size) {
    if(size < 2) {
        return 0;
    }
    int count = 0;
    for(int gap = size/2; gap > 0; gap /= 2) {
        for(int i = gap; i < size; i++) {
            T temp = array[i];
            int j;
            count++;
            for(j = i; j >= gap && array[j-gap] > temp; j-=gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
    return count;
}
