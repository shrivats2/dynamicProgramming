/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        function<TreeNode*(TreeNode*)>dfs=[&](TreeNode* curr)->TreeNode*
        {
            if(!curr) return curr;
            if(curr==p) return curr;
            if(curr==q) return curr;

            TreeNode *left=dfs(curr->left),*right=dfs(curr->right);
            if(!left)
              return right;
            else if(!right)
              return left;
           return curr; 
        };

        return dfs(root);
    }
};