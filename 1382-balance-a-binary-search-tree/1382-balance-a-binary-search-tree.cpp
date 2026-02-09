class Solution {
public:
    vector<int> inorderVals;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        inorderVals.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* buildBalanced(int l, int r) {
        if (l > r) return nullptr;

        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(inorderVals[mid]);

        root->left = buildBalanced(l, mid - 1);
        root->right = buildBalanced(mid + 1, r);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return buildBalanced(0, inorderVals.size() - 1);
    }
};
