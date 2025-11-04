class Solution {
public:
    int carFleet(
        int target, vector<int> &position, vector<int> &speed
    ) {
        int n = speed.size();

        vector<pair<int, double>> timings(n); 

        for (int i = 0; i < n; ++i) 
            timings[i] = {
                position[i],
                (double)(target - position[i]) / speed[i]
            };

        sort(timings.begin(), timings.end(), greater<>());

        u_int fleets = 0;
        double maxTime = 0.0;

        for (auto &[pos, time]: timings)
            if (time > maxTime) {
                ++fleets;
                maxTime = time;
            }

        return fleets;
    }
};