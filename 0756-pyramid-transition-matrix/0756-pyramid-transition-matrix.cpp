class Solution {
public:
    unordered_map<string, vector<char>> mp;

    bool dfs(string curr, string next, int idx) {
        if (curr.size() == 1) return true;

        if (idx == curr.size() - 1)
            return dfs(next, "", 0);

        string key = curr.substr(idx, 2);
        if (mp.find(key) == mp.end()) return false;

        for (char c : mp[key]) {
            if (dfs(curr, next + c, idx + 1))
                return true;
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0,2)].push_back(s[2]);
        }
        return dfs(bottom, "", 0);
    }
};
