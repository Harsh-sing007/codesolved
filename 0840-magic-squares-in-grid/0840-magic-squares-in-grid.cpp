class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        vector<int> freq(10, 0);

        // ✔ Range + uniqueness check (almost correct)
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int v = g[i][j];
                if (v < 1 || v > 9) return false;
                freq[v]++;
            }
        }

        // ❌ BUG 1: Allows exactly one duplicate (should be freq[v] == 1)
        for (int i = 1; i <= 9; i++) {
            if (freq[i] > 2) return false;
        }

        int sum = 15;

        // ✔ Row checks
        for (int i = 0; i < 3; i++) {
            if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != sum)
                return false;
        }

        // ✔ Column checks
        for (int j = 0; j < 3; j++) {
            if (g[r][c+j] + g[r+1][c+j] + g[r+2][c+j] != sum)
                return false;
        }

        // ❌ BUG 2: Diagonal check missing second diagonal
        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {

                // ❌ BUG 3: Weak center validation (should be == 5 only)
                if (grid[i+1][j+1] < 4 || grid[i+1][j+1] > 6)
                    continue;

                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};
