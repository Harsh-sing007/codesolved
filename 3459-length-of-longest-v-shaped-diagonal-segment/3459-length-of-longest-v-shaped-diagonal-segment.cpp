#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Define what the next digit should be for each current digit
        // Pattern: 1 -> 2 -> 0 -> 2 -> 0 -> 2 -> ...
        unordered_map<int, int> nextDigit = {{1, 2}, {2, 0}, {0, 2}};
        
        // Check if coordinates are within grid bounds
        auto withinBounds = [&](int i, int j) {
            return 0 <= i && i < m && 0 <= j && j < n;
        };
        
        // Memoization map for caching results
        // Key: "i,j,di,dj,turned" -> Value: max length from that state
        unordered_map<string, int> memo;
        
        // Recursive function to find max length from current position
        function<int(int, int, int, int, bool)> dfs = [&](int i, int j, int di, int dj, bool turned) -> int {
            // Create unique key for memoization
            string key = to_string(i) + "," + to_string(j) + "," + 
                        to_string(di) + "," + to_string(dj) + "," + to_string(turned);
            
            if (memo.find(key) != memo.end()) {
                return memo[key];
            }
            
            int result = 1; // Current cell contributes 1 to length
            int successor = nextDigit[grid[i][j]]; // What should come next in sequence
            
            // Try continuing in current direction
            int ni = i + di, nj = j + dj;
            if (withinBounds(ni, nj) && grid[ni][nj] == successor) {
                result = max(result, 1 + dfs(ni, nj, di, dj, turned));
            }
            
            // If we haven't turned yet, try making a 90-degree clockwise turn
            if (!turned) {
                // 90-degree clockwise turn: (di, dj) -> (dj, -di)
                int newDi = dj, newDj = -di;
                int ti = i + newDi, tj = j + newDj;
                
                if (withinBounds(ti, tj) && grid[ti][tj] == successor) {
                    result = max(result, 1 + dfs(ti, tj, newDi, newDj, true));
                }
            }
            
            memo[key] = result;
            return result;
        };
        
        // Four diagonal directions: 
        // (1,1): down-right, (-1,1): up-right, (1,-1): down-left, (-1,-1): up-left
        vector<pair<int, int>> directions = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
        int maxLength = 0;
        
        // Try starting from every cell that contains 1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // Only start from cells with value 1
                    // Try all four diagonal directions
                    for (auto [di, dj] : directions) {
                        maxLength = max(maxLength, dfs(i, j, di, dj, false));
                    }
                }
            }
        }
        
        return maxLength;
    }
};