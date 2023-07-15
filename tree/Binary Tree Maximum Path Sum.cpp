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
    int maxPathSum(TreeNode* root) 
    {
        int mx=-1e9;
        function<int(TreeNode*)>helper=[&](TreeNode* curr)
        {
            if(!curr)
              return 0;

            int left=max(0,helper(curr->left));
            int right=max(0,helper(curr->right));

            mx=max(mx,curr->val+left+right);

            return curr->val+max(left,right);  
        };
        helper(root);
        return mx;
    }
};