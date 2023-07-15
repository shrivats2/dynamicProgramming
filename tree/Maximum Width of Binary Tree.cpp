class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<unsigned long long, TreeNode*>> q;
        q.push({0, root});
        unsigned long long ans = 0;

        while (!q.empty()) {
            int t = q.size();
            auto i = q.front();
            unsigned long long left = i.first;
            unsigned long long right = 0;

            while (t--) {
                auto it = q.front();
                q.pop();

                unsigned long long r = it.first;

                right = max(right, r);

                if (it.second->left) {
                    q.push({2 * r + 1, it.second->left});
                }
                if (it.second->right) {
                    q.push({2 * r + 2, it.second->right});
                }
            }
            ans = max(right - left + 1, ans);
        }

        return ans;
    }
};
