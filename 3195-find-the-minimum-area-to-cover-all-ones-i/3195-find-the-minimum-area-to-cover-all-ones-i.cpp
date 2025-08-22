class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int top = rows, bottom = -1;
        int left = cols, right = -1;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    top = min(top, i);
                    bottom = max(bottom, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }

        // If no '1' is found, bottom == -1
        if (bottom == -1) return 0;

        int height = bottom - top + 1;
        int width = right - left + 1;
        return height * width;
    }
};
