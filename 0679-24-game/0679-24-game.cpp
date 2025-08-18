class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> a(cards.begin(), cards.end());
        return solve(a);
    }

private:
    static constexpr double EPS = 1e-6;

    bool solve(vector<double> nums) {
        int n = nums.size();
        if (n == 1) return fabs(nums[0] - 24.0) < EPS;

        // try all pairs
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) if (i != j) {
                vector<double> next;
                next.reserve(n - 1);
                for (int k = 0; k < n; ++k) if (k != i && k != j) next.push_back(nums[k]);

                // combine nums[i] and nums[j] in all ways
                for (double v : ops(nums[i], nums[j])) {
                    next.push_back(v);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> ops(double a, double b) {
        vector<double> res = {a + b, a - b, b - a, a * b};
        if (fabs(b) > EPS) res.push_back(a / b);
        if (fabs(a) > EPS) res.push_back(b / a);
        return res;
    }
};
