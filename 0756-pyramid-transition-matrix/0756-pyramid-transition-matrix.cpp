class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;
    bool dfs(string curr) {
        if (curr.size() == 1) return true;
        if (memo.count(curr)) return memo[curr];
        vector<string> choices(curr.size() - 1);
        for (int i = 0; i < curr.size() - 1; i++) {
            string key = curr.substr(i, 2);
            if (!mp.count(key))
                return memo[curr] = false;

            for (char c : mp[key])
                choices[i].push_back(c);
        }
        function<bool(int, string&)> build = [&](int idx, string &next) {
            if (idx == choices.size())
                return dfs(next);

            for (char c : choices[idx]) {
                next.push_back(c);
                if (build(idx + 1, next)) return true;
                next.pop_back();
            }
            return false;
        };
        string next = "";
        return memo[curr] = build(0, next);
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed)
            mp[s.substr(0, 2)].push_back(s[2]);

        return dfs(bottom);
    }
};
