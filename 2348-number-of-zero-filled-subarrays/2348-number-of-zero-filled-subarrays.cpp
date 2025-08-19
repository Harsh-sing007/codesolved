#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;  // total result
        long long streak = 0; // length of current zero streak

        for (int n : nums) {
            if (n == 0) {
                streak++;          // extend zero streak
                count += streak;   // add subarrays ending here
            } else {
                streak = 0;        // reset streak if non-zero
            }
        }
        return count;
    }
};
