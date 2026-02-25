#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int countBits(int n) {
        int count = 0;
        while(n>0){
            if(n%2==1)
                count++;
            n=n/2;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(), arr.end(), [&](int a, int b){

            int c1 = countBits(a);
            int c2 = countBits(b);

            if(c1==c2)
                return a<b;

            return c1<c2;
        });

        return arr;
    }
};