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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        vector<vector<int>>ans;

        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty())
        {
                auto i=q.front();
                q.pop();
            
                int a=i.second.first,b=i.second.second;
                    mp[a][b].insert(i.first->val);
                if(i.first->left)
                {
                    q.push({i.first->left,{a-1,b+1}});
                }
                if(i.first->right)
                {
                    q.push({i.first->right,{a+1,b+1}});
                }
               
        }

        for(auto i:mp)
        {
            vector<int>res;
            for(auto j:i.second)
            {
                 res.insert(res.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(res);
        }

        return ans;
    }
};