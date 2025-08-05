class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false);
        int unplaced = n;

        for (int x : fruits) {
            for (int j = 0; j < n; ++j) {
                if (!used[j] && baskets[j] >= x) {
                    used[j] = true;
                    --unplaced;
                    break;
                }
            }
        }
        return unplaced;
    }
};
