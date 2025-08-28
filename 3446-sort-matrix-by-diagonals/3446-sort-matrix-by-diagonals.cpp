class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diag;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                diag[i - j].push_back(grid[i][j]);
        for (auto& [key, vec] : diag) {
            if (key < 0)
                sort(vec.begin(), vec.end(), greater<int>());  // non-increasing
            else
                sort(vec.begin(), vec.end());                
        }
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto& vec = diag[i - j];
                res[i][j] = vec.back();
                vec.pop_back();
            }
        }
        return res;
    }
};
