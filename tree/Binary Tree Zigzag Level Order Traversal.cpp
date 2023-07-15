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
        vector<vector<int>>ans;
        if(!root)
         return ans;
        queue<TreeNode*>q;
        q.push(root);
        int i=0;
        bool leftToRight = true;
         
        while(!q.empty())
        {
           int sz=q.size();
           vector<int>v(sz);
           for (int j = 0; j <sz;j++)
           {
               TreeNode * t=q.front();
               int k=(leftToRight) ? j: (sz - 1 - j);
               v[k]=(q.front()->val);
               q.pop();
               if(t->left)q.push(t->left);
               if(t->right)q.push(t->right);
           }
           leftToRight=!leftToRight;
           ans.push_back(v);
        }
        return ans;
    }
};