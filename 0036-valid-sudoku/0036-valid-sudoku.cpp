#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rowSet, colSet, boxSet;
            for (int j = 0; j < 9; j++) {
                // Check row
                if (board[i][j] != '.') {
                    if (rowSet.count(board[i][j])) return false;
                    rowSet.insert(board[i][j]);
                }

                // Check column
                if (board[j][i] != '.') {
                    if (colSet.count(board[j][i])) return false;
                    colSet.insert(board[j][i]);
                }

                // Check 3x3 box
                int r = 3 * (i / 3) + j / 3;
                int c = 3 * (i % 3) + j % 3;
                if (board[r][c] != '.') {
                    if (boxSet.count(board[r][c])) return false;
                    boxSet.insert(board[r][c]);
                }
            }
        }
        return true;
    }
};
