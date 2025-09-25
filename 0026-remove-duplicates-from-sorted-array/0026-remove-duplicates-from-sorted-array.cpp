class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // handle empty array

        int i = 0; // slow pointer for unique elements
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j]; // place next unique element
            }
        }
        return i + 1; 
    }
};
