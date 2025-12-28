class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int currValue = events[i][2];
            ans = max(ans, currValue); 
            int l = i + 1, r = n - 1, next = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (events[mid][0] > events[i][1]) {
                    next = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (next != -1) {
                ans = max(ans, currValue + suffixMax[next]);
            }
        }
        return ans;
    }
};
