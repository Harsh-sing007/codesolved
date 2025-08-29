#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddN = (n + 1) / 2;   // number of odd flowers in pile 1
        long long evenN = n / 2;        // number of even flowers in pile 1
        long long oddM = (m + 1) / 2;   // number of odd flowers in pile 2
        long long evenM = m / 2;        // number of even flowers in pile 2
        
        // Alice wins if total flowers picked each turn is odd
        // That happens when:
        // pile1 is odd & pile2 is even, OR pile1 is even & pile2 is odd
        return oddN * evenM + evenN * oddM;
    }
};
