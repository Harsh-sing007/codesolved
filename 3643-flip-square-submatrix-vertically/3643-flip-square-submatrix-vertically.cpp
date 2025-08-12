class Solution {
public:
    vector<vector<int>> flipVertically(
        vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; ++i) {
            swap(grid[x + i], grid[x + (k - 1 )]);
        }
        return grid;
    }
};
