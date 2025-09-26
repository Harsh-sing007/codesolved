class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Count occurrences of each color
        int count0 = 0, count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == 0) count0++;
            else if (num == 1) count1++;
            else count2++;
        }

        // Overwrite the array based on counts
        int index = 0;
        while (count0--) nums[index++] = 0;
        while (count1--) nums[index++] = 1;
        while (count2--) nums[index++] = 2;
    }
};
