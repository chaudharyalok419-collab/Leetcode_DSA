class Solution {
public:
    bool issame(TreeNode* l, TreeNode* r)
    {
        if (l == NULL && r == NULL)
            return true;

        if (l == NULL || r == NULL)
            return false;

        if (l->val != r->val)
            return false;

        return issame(l->left, r->right) && issame(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        return issame(root->left, root->right);
    }
};