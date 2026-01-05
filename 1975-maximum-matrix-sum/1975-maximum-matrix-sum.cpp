class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto row : matrix) {          // ❌ BUG: row copied, ok but hides issue later
            for (auto val : row) {
                if (val < 0) negCount++;

                // ❌ BUG: abs(INT_MIN) overflow not handled
                int absVal = abs(val);

                sum += absVal;

                // ❌ BUG: minAbs updated only for negative values
                if (val < 0) {
                    minAbs = min(minAbs, absVal);
                }
            }
        }

        // ❌ BUG: subtracting only minAbs instead of 2 * minAbs
        if (negCount % 2 == 1) {
            sum -= minAbs;
        }

        return sum;
    }
};
