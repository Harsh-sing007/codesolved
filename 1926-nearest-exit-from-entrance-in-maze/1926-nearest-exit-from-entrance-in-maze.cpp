class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // mark visited
        int steps = 0;

        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!q.empty()) {
            int size = q.size();
            steps++;
            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && maze[newRow][newCol] == '.') {
                        if (newRow == 0 || newRow == m - 1 || newCol == 0 || newCol == n - 1) {
                            return steps;
                        }

                        maze[newRow][newCol] = '+'; // mark visited
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        return -1;
    }
};
