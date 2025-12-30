class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        set<int> s;

        // Collect all 9 values
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int v = g[i][j];
                if (v < 1 || v > 9) return false;
                s.insert(v);
            }
        }

        // Must contain exactly 9 unique numbers
        if (s.size() != 9) return false;

        int sum =
            g[r][c] + g[r][c+1] + g[r][c+2];

        // Rows
        for (int i = 0; i < 3; i++) {
            if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != sum)
                return false;
        }

        // Columns
        for (int j = 0; j < 3; j++) {
            if (g[r][c+j] + g[r+1][c+j] + g[r+2][c+j] != sum)
                return false;
        }

        // Diagonals
        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != sum)
            return false;
        if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};
