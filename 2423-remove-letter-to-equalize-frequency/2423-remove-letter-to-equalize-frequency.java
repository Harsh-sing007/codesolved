import java.util.*;

class Solution {
    public boolean equalFrequency(String word) {
        int[] freq = new int[26];
        
        // Count frequency of each character
        for (char c : word.toCharArray()) {
            freq[c - 'a']++;
        }
        
        // Try removing each character and check if frequencies become equal
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            
            freq[i]--;
            
            if (isValid(freq)) return true;
            
            freq[i]++;
        }
        
        return false;
    }
    
    private boolean isValid(int[] freq) {
        int commonFreq = 0;
        
        for (int count : freq) {
            if (count == 0) continue;
            if (commonFreq == 0) {
                commonFreq = count;
            } else if (count != commonFreq) {
                return false;
            }
        }
        return true;
    }
}
