/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* build(vector<int>& nums, int left, int right, int &index) {
        if(left > right)
            return NULL;
        
        int mid = left + (right - left) / 2;
        TreeNode* leftChild = build(nums, left, mid - 1, index);
        TreeNode* root = new TreeNode(nums[index++]);
        root->left = leftChild;
        root->right = build(nums, mid + 1, right, index);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int index = 0;
        return build(nums, 0, nums.size() - 1, index);
    }
};
