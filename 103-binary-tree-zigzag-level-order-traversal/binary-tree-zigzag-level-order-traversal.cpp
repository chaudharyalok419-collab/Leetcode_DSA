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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==NULL)
           return {};
           vector<vector<int>>ans;
          queue<TreeNode *>q;
          q.push(root);
          bool flag = false ;
          while (!q.empty())
          {    int s= q.size();
                
                 vector<int>ans1;
                while (s--)
                {
                    auto t= q.front();
                    q.pop();
                     ans1.push_back(t->val);
                       if (t->left )
                       q.push(t->left);
                        if (t->right)
                          q.push(t->right);
                
                }
                
                 
          
            if (flag)
              reverse(ans1.begin(),ans1.end());
               flag = true^flag;
                ans.push_back(ans1);

          }
          return ans;
         
    }
};