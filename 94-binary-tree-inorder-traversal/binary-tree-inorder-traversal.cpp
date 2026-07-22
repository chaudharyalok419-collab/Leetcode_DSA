class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
            else {
                st.pop();
                mpp[it]=1;
                ans.push_back(it->val);
              
                if (it->right != NULL && mpp[it->right] != 1) {
                    st.push(it->right);
                
    
                }
            }
        }

        return ans;
    }
};