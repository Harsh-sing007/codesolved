class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0, total = 0;

        for (int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        for (auto [key, val] : freq) {
            if (val == maxFreq)
                total += val;
        }

        return total;
    }
};
