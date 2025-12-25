class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long total = 0;
        
        for (int i = 0; i < k; i++) {
            int current = happiness[i] - i;
            if (current <= 0) break;
            total += current;
        }
        
        return total;
    }
};
