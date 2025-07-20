import java.util.*;

class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        if (n1 == 0) return 0;
        
        int s1Len = s1.length(), s2Len = s2.length();
        int index = 0, countS2 = 0;
        Map<Integer, int[]> map = new HashMap<>();
        
        for (int countS1 = 1; countS1 <= n1; countS1++) {
            for (int i = 0; i < s1Len; i++) {
                if (s1.charAt(i) == s2.charAt(index)) {
                    index++;
                    if (index == s2Len) {
                        index = 0;
                        countS2++;
                    }
                }
            }
            
            if (map.containsKey(index)) {
                int[] previous = map.get(index);
                int preCountS1 = previous[0], preCountS2 = previous[1];
                
                int cycleLength = countS1 - preCountS1;
                int cycleCountS2 = countS2 - preCountS2;
                
                int remainingS1 = n1 - countS1;
                int cycles = remainingS1 / cycleLength;
                
                countS2 += cycles * cycleCountS2;
                countS1 += cycles * cycleLength;
                
                // Remaining part after cycles will be handled in remaining iterations
            }
            
           
        }
        
        return countS2 / n2;
    }
}
