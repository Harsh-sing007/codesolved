class Solution {
    public int maximumLength(int[] nums) {
        int evenCount = 0, oddCount = 0;
        int altLength = 0;
        Integer lastParity = null;
        
        for (int x : nums) {
            if (x % 2 == 0) evenCount++;
            else oddCount++;
            
            int currentParity = x % 2;
            if (lastParity == null || currentParity != lastParity) {
                altLength++;
                lastParity = currentParity;
            }
        }
        
        return Math.max(Math.max(evenCount, oddCount), altLength);
    }
}
