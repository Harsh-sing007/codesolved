#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : arr) {
            freq[num]++;
        }

        int result = -1;
        for (auto& [num, count] : freq) {
            if (num == count) {
                result = max(result, num); // We want the largest lucky integer
            }
        }

        return result;
    }
};
