class Solution {
public:
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return (s->val == t->val) && isSame(s->left, t->left) && isSame(s->right, t->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
