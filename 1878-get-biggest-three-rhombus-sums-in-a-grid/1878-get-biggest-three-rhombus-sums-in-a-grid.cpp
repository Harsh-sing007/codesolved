class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        set<int, greater<int>> st;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                st.insert(grid[i][j]);  // size 0 rhombus

                for(int k = 1; k < max(m,n); k++){

                    if(i + 2*k >= m || j - k < 0 || j + k >= n)
                        break;

                    int sum = 0;

                    int x = i, y = j;

                    // left-down edge
                    for(int t = 0; t < k; t++)
                        sum += grid[x + t][y - t];

                    // bottom-left to bottom
                    for(int t = 0; t < k; t++)
                        sum += grid[x + k + t][y - k + t];

                    // right-up edge
                    for(int t = 0; t < k; t++)
                        sum += grid[x + 2*k - t][y + t];

                    // top-right edge
                    for(int t = 0; t < k; t++)
                        sum += grid[x + k - t][y + k - t];

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;

        for(auto v : st){
            ans.push_back(v);
            if(ans.size() == 3)
                break;
        }

        return ans;
    }
};