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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root==NULL)
           return {};
        stack<TreeNode*>st;
        unordered_map<TreeNode*,int>mpp;
        vector<int>ans;
        ans.push_back(root->val);
        st.push(root);
        mpp[root]=1;
        while (!st.empty())
        {   auto it = st.top();
             
            if (it->left !=NULL && mpp[it->left]!=1)
             {
                st.push(it->left);
                ans.push_back(it->left->val);
                mpp[it->left]=1;
             }
             else{
                st.pop();
                  if (it->right!=NULL )
                    {
                        st.push(it->right);
                      ans.push_back(it->right->val);
                    }
                    
             }
            
               
            
        }
        return ans;
        
    }
};