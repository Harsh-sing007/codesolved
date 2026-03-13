class Solution {
public:

    bool canFinish(long long time, int mountainHeight, vector<int>& workerTimes) {
        long long total = 0;

        for(int t : workerTimes) {

            long long k = (sqrt(1 + (8.0 * time) / t) - 1) / 2;

            total += k;

            if(total >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long left = 0;
        long long right = 1e18;
        long long ans = right;

        while(left <= right) {

            long long mid = left + (right - left) / 2;

            if(canFinish(mid, mountainHeight, workerTimes)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};