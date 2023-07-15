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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        map<int,int>mp;

        for(int i=0;i<n;i++)
        {
          mp[inorder[i]]=i;
        }

        function<TreeNode*(int,int,int,int)>help=[&](int is,int ie,int ps,int pe)->TreeNode*
        {
            if(ps>pe||is>ie) return NULL;
            int idx=mp[postorder[pe]],leftidx=idx-is;

            TreeNode* root=new TreeNode(postorder[pe]);

            root->left=help(is,idx-1,ps,ps+leftidx-1);
            root->right=help(idx+1,ie,ps+leftidx,pe-1);

            return root;
        };

        return help(0,n-1,0,n-1);  
    }
};