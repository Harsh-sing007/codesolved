class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefOrig(n+1,0), prefPrice(n+1,0);

        for(int i=0;i<n;i++){
            prefOrig[i+1] = prefOrig[i] + (long long)strategy[i]*prices[i];
            prefPrice[i+1] = prefPrice[i] + prices[i];
        }

        long long baseProfit = prefOrig[n];
        long long bestDelta = 0;

        // Slide window of size k
        for(int end = k; end <= n; end++){
            long long oldSum   = prefOrig[end] - prefOrig[end-k];
            long long newSum   = prefPrice[end] - prefPrice[end - k/2];
            long long delta    = newSum - oldSum;
            bestDelta = max(bestDelta, delta);
        }

        return baseProfit + bestDelta;
    }
};
