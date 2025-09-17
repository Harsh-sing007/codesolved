class Solution {
public:
    int searchInsert(vector<int>& a, int key) {
        int lo = 0;
        int hi = (int)a.size() - 1;

     
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1); 

            if (a[mid] == key) {
                return mid;  
            }
            if (a[mid] < key) {
                lo = mid + 1;  
            } else {
                hi = mid - 1;  
            }
        }
       
        return lo;
    }
};
