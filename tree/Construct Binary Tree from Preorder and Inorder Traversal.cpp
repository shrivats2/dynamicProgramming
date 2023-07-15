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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size(),m=inorder.size();
        int ps=0,pe=n-1,is=0,ie=m-1;

        map<int,int>mp;
        for(int i=0;i<m;i++)
        {
           mp[inorder[i]]=i; 
        }

        function<TreeNode*(int,int,int,int)>helper=[&](int ps,int pe,int is,int ie)->TreeNode*
        {
           if(ps>pe||is>ie) return NULL; 

           TreeNode* root=new TreeNode(preorder[ps]);
           int idx=mp[preorder[ps]]; 
           root->left=helper(ps+1,ps+idx-is,is,idx-1);
           root->right=helper(ps+(idx-is)+1,pe,idx+1,ie);

           return root; 
        };

        return helper(0,n-1,0,m-1);
    }
};