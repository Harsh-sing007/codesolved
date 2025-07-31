class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> cur, prev;

        for (int num : arr) {
            unordered_set<int> temp;
            temp.insert(num);
            for (int val : prev) {
                temp.insert(val | num);
            }
            prev = temp;
            result.insert(temp.begin(), temp.end());
        }

        return result.size();
    }
};
