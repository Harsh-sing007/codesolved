class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 1, r = row * col;   // ❌ bug: upper bound incorrect
        int res = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canCross(row, col, cells, mid)) {
                res = mid;
                l = mid;           // ❌ bug: infinite loop possible
            } else {
                r = mid - 1;
            }
        }
        return res;
    }

    bool canCross(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        // ❌ bug: wrong flooding order
        for (int i = day - 1; i >= 0; i--) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        vector<vector<int>> vis(row, vector<int>(col, 0));

        // ❌ bug: DFS only from (0,0)
        if (grid[0][0] == 1) return false;
        dfs(0, 0, grid, vis, row, col);

        // ❌ bug: checks only last column
        for (int i = 0; i < row; i++) {
            if (vis[i][col - 1]) return true;
        }
        return false;
    }

    void dfs(int r, int c, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int row, int col) {

        if (r < 0 || r >= row || c < 0 || c >= col) return;
        if (grid[r][c] == 1 || vis[r][c]) return;

        vis[r][c] = 1;

        dfs(r + 1, c, grid, vis, row, col);
        dfs(r - 1, c, grid, vis, row, col);
        dfs(r, c + 1, grid, vis, row, col);
        dfs(r, c - 1, grid, vis, row, col);
    }
};
