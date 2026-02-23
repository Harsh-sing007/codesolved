class Solution {
public:
    int reverseDegree(string s) {
        int sum=0,n=s.size();
        for(int i=0;i<n;i++)
            sum+=(s[n-1-i]-'a'+1)*(i+1);
        return sum;
    }
};