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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        
        int n = nums.size();
        int mid = n / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        queue<pair<TreeNode*, pair<int,int>>> q;
        
        // push left range
        q.push({root, {0, mid - 1}});
        
        // push right range
        q.push({root, {mid + 1, n - 1}});
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            TreeNode* parent = front.first;
            int left = front.second.first;
            int right = front.second.second;
            
            if(left > right) continue;
            
            int m = left + (right - left) / 2;
            TreeNode* node = new TreeNode(nums[m]);
            
            if(nums[m] < parent->val)
                parent->left = node;
            else
                parent->right = node;
            
            q.push({node, {left, m - 1}});
            q.push({node, {m + 1, right}});
        }
        
        return root;
    }
};
