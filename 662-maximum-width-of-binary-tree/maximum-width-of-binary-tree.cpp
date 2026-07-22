class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int ans = 0;

        while (!q.empty()) {
            int s = q.size();

            long long first = q.front().second;
            long long left = 0, right = 0;

            for (int i = 0; i < s; i++) {
                auto [node, idx] = q.front();
                q.pop();

                idx -= first;         

                if (i == 0) left = idx;
                if (i == s - 1) right = idx;

                if (node->left)
                    q.push({node->left, 2 * idx});

                if (node->right)
                    q.push({node->right, 2 * idx + 1});
            }

            ans = max(ans, (int)(right - left + 1));
        }

        return ans;
    }
};