class Solution {
public:
    int count = 0;

    pair<int, int> sum(TreeNode* root)
    {
        if (root == NULL)
            return {0, 0};

        pair<int, int> left = sum(root->left);
        pair<int, int> right = sum(root->right);

        int a = root->val + left.first + right.first;  
        int b = 1 + left.second + right.second;      

        return {a, b};
    }

    void helper(TreeNode* root)
    {
        if (root == NULL)
            return;

        pair<int, int> p = sum(root);

        int x = p.first; 
        int y = p.second; 

        if (x / y == root->val)
            count++;

        helper(root->left);
        helper(root->right);
    }

    int averageOfSubtree(TreeNode* root)
    {
        helper(root);
        return count;
    }
};