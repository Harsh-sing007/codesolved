class Solution {
public:
    void solve(int n, string curr, vector<string>& res) {
        if(curr.length() == n) {
            res.push_back(curr);
            return;
        }
        for(char ch : {'a','b','c'}) {
            if(curr.empty() || curr.back() != ch) {
                solve(n, curr + ch, res);
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> res;
        solve(n, "", res);
        if(k > res.size()) return "";
        return res[k-1];
    }
};