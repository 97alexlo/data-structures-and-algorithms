//
//  main.cpp
//  Exercise10
//
//  Created by Alex Lo on 2020-07-17.
//  Copyright © 2020 Alex Lo. All rights reserved.
//

#include <iostream>
#include "Exercise10.h"

using namespace std;

int main() {
    vector<string> words = { "dog","cat","apt","sue","bob","dam","and","ape","zvz","dim"};
    vector<string> words1;
    int len = 3;
    radixsort(words, len);
    for(int i = 0; i < words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;
}
