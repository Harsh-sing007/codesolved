class Solution {
    int max = 0;
    int count = 0;

    public int countMaxOrSubsets(int[] nums) {

        for (int num : nums) {
            max |= num;
        }
        dfs(nums, 0, 0);
        return count;
    }

    private void dfs(int[] nums, int index, int currOr) {
        if (index == nums.length) {
            if (currOr == max) {
                count++;
            }
            return;
        }

        // Include nums[index]
        dfs(nums, index + 1, currOr | nums[index]);

        // Exclude nums[index]
        dfs(nums, index + 1, currOr);
    }
}
