class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        constexpr int MOD = 1'000'000'007;
        vector<int> ans, pows;
        for (int i = 0; i < 30; ++i) {
            if (n >> i & 1) {
                pows.push_back(1 << i);
            }
        }
        for (auto& q : queries) {
            long prod = 1;
            for (int i = q[0]; i <= q[1]; ++i) {
                prod = (prod * pows[i]) % MOD;
            }
            ans.push_back((int) prod);
        }

        return ans;
    }
};
