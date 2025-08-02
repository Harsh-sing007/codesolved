class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;
        for (int b : basket1) freq[b]++;
        for (int b : basket2) freq[b]--;

        vector<int> excess;
        int globalMin = min(*min_element(basket1.begin(), basket1.end()),
                            *min_element(basket2.begin(), basket2.end()));

        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0) return -1; // not possible
            for (int i = 0; i < abs(count) / 2; ++i)
                excess.push_back(fruit);
        }

        sort(excess.begin(), excess.end());
        long long cost = 0;

        for (int i = 0; i < excess.size() / 2; ++i) {
            cost += min((long long)excess[i], 2LL * globalMin);
        }

        return cost;
    }
};
