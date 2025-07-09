class Solution {
public:
    long long maxFreeTime(long long eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<long long> gaps;
        gaps.reserve(n + 1);

        // Compute gaps
        gaps.push_back((long long)startTime[0]);  // Before first meeting
        for (int i = 1; i < n; i++) {
            gaps.push_back((long long)startTime[i] - (long long)endTime[i - 1]);  // Between meetings
        }
        gaps.push_back((long long)eventTime - (long long)endTime[n - 1]);  // After last meeting

        // Sliding window of size (k+1)
        long long windowSum = 0, maxFree = 0;
        int windowSize = k + 1;

        for (int i = 0; i < gaps.size(); i++) {
            windowSum += gaps[i];
            if (i >= windowSize) windowSum -= gaps[i - windowSize];
            if (i >= windowSize - 1) maxFree = max(maxFree, windowSum);
        }

        return maxFree;
    }
};
