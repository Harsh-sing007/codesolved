class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<long long> incL(n), dec(n), incR(n);

        incL[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                incL[i] = incL[i - 1] + nums[i];
            else
                incL[i] = nums[i];
        }

        dec[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1])
                dec[i] = dec[i + 1] + nums[i];
            else
                dec[i] = nums[i];
        }

        incR[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                incR[i] = incR[i + 1] + nums[i];
            else
                incR[i] = nums[i];
        }

        long long ans = LLONG_MIN;

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] < nums[i + 1]) {
                for (int j = i + 1; j < n - 1; j++) {
                    if (nums[j] > nums[j + 1]) {
                        if (j + 1 < n && nums[j] < nums[j + 1]) continue;
                        ans = max(ans, incL[i] + dec[i + 1] + incR[j + 1]);
                    }
                }
            }
        }

        return ans;
    }
};
