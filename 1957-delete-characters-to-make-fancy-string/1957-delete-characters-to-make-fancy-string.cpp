#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
                if (count < 3) result += s[i];
            } else {
                count = 1;
                result += s[i];
            }
        }

        // Add the first character because we started loop from index 1
        return s.empty() ? "" : s[0] + result;
    }
};
