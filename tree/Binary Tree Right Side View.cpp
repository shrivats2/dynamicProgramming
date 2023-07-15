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
        vector<int>ans;
        map<int,int>mp;
        if(root==NULL) return ans;
        
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            auto i=q.front();
            q.pop();
            
            int x=i.second;
            
            mp[x]=i.first->val;
            
            if(i.first->left)
            {
                q.push({i.first->left,x+1});
            }
            if(i.first->right)
            {
                q.push({i.first->right,x+1});
            }
            
        }
        
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};