class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            int cnt = 0, sum = 0;
            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    int d1 = i, d2 = n / i;

                    if (d1 == d2) {
                        cnt++;
                        sum += d1;
                    } else {
                        cnt += 2;
                        sum += d1 + d2;
                    }

                    if (cnt > 4) break;
                }
            }
            if (cnt == 4) ans += sum;
        }
        return ans;
    }
};
