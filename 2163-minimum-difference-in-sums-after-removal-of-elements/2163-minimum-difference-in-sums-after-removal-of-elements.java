import java.util.*;

class Solution {
    public long minimumDifference(int[] nums) {
        int n = nums.length / 3;
        int len = nums.length;
        long[] leftSum = new long[len];
        long[] rightSum = new long[len];

        // Left sum: smallest n elements from first 2n
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        long left = 0;
        for (int i = 0; i < len; i++) {
            left += nums[i];
            maxHeap.offer(nums[i]);
            if (maxHeap.size() > n) {
                left -= maxHeap.poll();
            }
            if (i >= n - 1) {
                leftSum[i] = left;
            }
        }

        // Right sum: largest n elements from last 2n
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        long right = 0;
        for (int i = len - 1; i >= 0; i--) {
            right += nums[i];
            minHeap.offer(nums[i]);
            if (minHeap.size() > n) {
                right -= minHeap.poll();
            }
            if (i <= len - n) {
                rightSum[i] = right;
            }
        }

        long ans = Long.MAX_VALUE;
        for (int i = n - 1; i < 2 * n; i++) {
            ans = Math.min(ans, leftSum[i] - rightSum[i + 1]);
        }

        return ans;
    }
}
