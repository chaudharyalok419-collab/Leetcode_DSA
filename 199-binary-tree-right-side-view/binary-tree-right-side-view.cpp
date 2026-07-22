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
    vector<int> rightSideView(TreeNode* root) {
        if (root==NULL)
          {
            return {};
          }
        queue<TreeNode*> q;
        vector <int> ans;
        q.push(root);
         while (!q.empty())
         {
           
           int s= q.size();
            bool f= true;
            while (s--)
            {   auto it = q.front();
                if (f)
                  {
                    ans.push_back(it->val);
                     f=0;
                  }
                  if (it->right)
                    {
                        q.push(it->right);

                    }
                    if (it->left )
                      q.push(it->left);

                      q.pop();
                      
            }
             
            
         }
         return ans;
        
        
        
    }
};