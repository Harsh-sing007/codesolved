#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;
        
        for (auto &word : words) {
            string temp;
            for (char c : word) {
                if (c == separator) {
                    if (!temp.empty()) {
                        result.push_back(temp);
                        temp.clear();
                    }
                } else {
                    temp += c;
                }
            }
            if (!temp.empty()) {
                result.push_back(temp);
            }
        }
        
        return result;
    }
};
