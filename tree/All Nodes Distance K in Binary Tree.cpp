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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,vector<TreeNode*>>adj;
        vector<int>ans;

        if(k==0)
        {
            ans.push_back(target->val);
            return ans;
        }

        function<void(TreeNode*)>preorder=[&](TreeNode* curr)
        {
            if(!curr||!curr->left and !curr->right) return ;

           if(curr->left)
           {
               adj[curr].push_back(curr->left);
               adj[curr->left].push_back(curr);
           }
           if(curr->right)
           {
               adj[curr].push_back(curr->right);
               adj[curr->right].push_back(curr);
           }

           preorder(curr->left);
           preorder(curr->right); 
        };
        preorder(root);

        int lvl=0;
        queue<TreeNode*>q;
        q.push(target);
        map<int,int>vis;

        while(!q.empty())
        {
            int t=q.size();
            while(t--)
            {
                auto i=q.front();
                q.pop();
                if(lvl==k)
                {
                   if(i->val!=target->val) 
                    ans.push_back(i->val);
                  
                }
                for(auto it:adj[i])
                {
                    if(vis[it->val]<=0)
                    {
                        vis[it->val]=1;
                        q.push(it);
                    }
                }
            }
            if(lvl==k)break;
            lvl++;
        }
        return ans;
    }
};