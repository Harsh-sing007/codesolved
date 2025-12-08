class Solution {
public:
    // bool isIsomorphic(string s, string t) {
        
    // }
    bool isIsomorphic(string s1, string s2) {
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        
        if(s1.length() != s2.length()) return false;
        
        for(int i = 0; i<s1.length(); i++){
            if(m1.find(s1[i]) == m1.end() and m2.find(s2[i]) == m2.end()){
                m1[s1[i]] = s2[i];
                m2[s2[i]] = s1[i];
            }else{
                if(m1[s1[i]] != s2[i] or m2[s2[i]] != s1[i]) return false;
            }
            
        }
        return true;
        
        
    }
};