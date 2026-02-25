#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<int> sortByBits(vector<int>& arr) {
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<arr.size();i++){
            int bits = __builtin_popcount(arr[i]);
            v.push_back({bits, arr[i]});
        }
        
        sort(v.begin(), v.end());
        
        for(int i=0;i<arr.size();i++){
            arr[i] = v[i].second;
        }
        
        return arr;
    }
};