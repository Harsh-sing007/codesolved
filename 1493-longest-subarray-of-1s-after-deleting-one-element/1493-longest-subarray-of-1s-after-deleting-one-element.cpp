#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeroCount = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeroCount++;

            // Shrink window until there's at most one zero
            while (zeroCount > 1) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }

            // Length minus one because we must delete exactly one element
            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};
