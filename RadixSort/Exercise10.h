//
//  Exercise10.h
//  cmpt225
//
//  Created by Alex Lo on 2020-07-17.


#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

void radixsort(vector<string> &words, int len) {
    vector<string> sorted(words.size());
    for(int digit = len-1; digit >= 0 ; digit--) {
        vector<int> count(27);
        for(int i = 0; i < 26; i++) {
            count.push_back(0);
        }
        for(int i = 0; i < words.size(); i++) {
            if(words[i][digit] == 'z') {
                continue;
            }
            count[(words[i][digit]) - 96]++;
        }
        for(int i = 1; i < 26; i++) {
            count[i] += count[i-1];
        }
        for(int i = 0; i < words.size(); i++) {
            sorted[count[(words[i][digit]) - 97]++] = words[i];
        }
        for(int i = 0; i < words.size(); i++) {
            words[i] = sorted[i];
        }
        count.clear();
    }
}
