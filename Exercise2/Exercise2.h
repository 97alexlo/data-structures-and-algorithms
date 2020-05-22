//
//  Exercise2.h
//  cmpt225
//  A function to remove a given value from an integer array, which may contain duplicates of the value to be removed. Elements above the removed values should be moved down one index, the order of the array elements stays unchanged. Return the number of values that were removed and should also set the integer reference parameter to the new number of values in the array.
//  Created by Alex Lo on 2020-05-21.



#pragma once

int remove(int array[], int & arraySize, int intToRemove) {
    int numRemoved = 0;
    int tempSize = arraySize;
    
    for(int i = 0; i < arraySize; i++) {
        if(array[i] == intToRemove) {
            numRemoved++;
            tempSize--;
        }
    }
    
    for(int i = 0; i < numRemoved; i++) {
        for(int j = 0; j < arraySize; j++) {
            if(array[j] == intToRemove) {
                for(int k = j; k < arraySize; k++) {
                    array[k] = array[k+1];
                }
            }
        }
    }
    
    arraySize = tempSize;
    
    return numRemoved;
}
