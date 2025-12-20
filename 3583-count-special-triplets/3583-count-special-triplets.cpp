class Solution {
public:
    static const int MOD = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, long long> right, left;

        // Fill right frequency map
        for (int x : nums) right[x]++;

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            right[nums[j]]--;  // current j is no longer on right side

            long long twice = nums[j] * 2LL;

            if (left.count(twice) && right.count(twice)) {
                ans = (ans + left[twice] * right[twice]) % MOD;
            }

            left[nums[j]]++;
        }

        return (int)ans;
    }
};

