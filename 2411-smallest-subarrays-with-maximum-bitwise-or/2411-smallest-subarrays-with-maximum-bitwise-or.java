class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int[] lastSeen = new int[32]; 
        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 32; b++) {
                if (((nums[i] >> b) & 1) == 1) {
                    lastSeen[b] = i;
                }
            }
            int maxIdx = i;
            for (int b = 0; b < 32; b++) {
                maxIdx = Math.max(maxIdx, lastSeen[b]);
            }
            ans[i] = maxIdx - i + 1;
        }
        return ans;
    }
}
