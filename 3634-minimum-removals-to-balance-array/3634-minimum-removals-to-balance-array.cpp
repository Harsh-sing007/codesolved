class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = n;
        int l = 0;

        for (int r = 0; r < n; r++) {
            while ((long long)nums[r] > (long long)nums[l] * k) {
                l++;
            }
            ans = min(ans, n - (r - l + 1));
        }

        return ans;
    }
};
