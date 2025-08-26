#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = 0.0;
        int maxArea = 0;

        for (auto &dim : dimensions) {
            int w = dim[0], h = dim[1];
            double diagonal = sqrt((double)w * w + (double)h * h);
            int area = w * h;

            if (diagonal > maxDiagonal) {
                maxDiagonal = diagonal;
                maxArea = area;
            } else if (fabs(diagonal - maxDiagonal) < 1e-9) { 
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
