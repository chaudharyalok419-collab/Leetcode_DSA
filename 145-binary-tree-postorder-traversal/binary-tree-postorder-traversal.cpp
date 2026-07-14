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
  vector<int>ans;
  void postorder(TreeNode *t)
    {  if (t==NULL)
        return ;
        postorder(t->left);
         postorder(t->right);
         ans.push_back(t->val);
         
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
        
    }
};
    