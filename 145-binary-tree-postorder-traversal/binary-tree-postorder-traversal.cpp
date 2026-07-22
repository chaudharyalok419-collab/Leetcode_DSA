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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {};

        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> mpp;
        vector<int> ans;

        st.push(root);

        while (!st.empty()) {
            auto it = st.top();

            if (it->left != NULL && mpp[it->left] != 1) {
                st.push(it->left);
                
            }
            else if (it->right!= NULL && mpp[it->right] != 1) {
                st.push(it->right);
                
            }
              else{
                 st.pop();
                 ans.push_back(it->val);
                  mpp[it]=1;
              }    
               

                
            }
    

        return ans;
    }
};