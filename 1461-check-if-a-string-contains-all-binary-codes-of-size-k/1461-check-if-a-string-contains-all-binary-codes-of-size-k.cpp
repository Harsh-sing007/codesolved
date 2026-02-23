class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = 1<<k;
        vector<bool> seen(need,false);

        int hash=0;
        int allOneMask=need-1;
        int count=0;

        for(int i=0;i<s.size();i++){

            hash=((hash<<1)&allOneMask) | (s[i]-'0');

            if(i>=k-1 && !seen[hash]){
                seen[hash]=true;
                count++;
            }

            if(count==need)
                return true;
        }

        return false;
    }
};