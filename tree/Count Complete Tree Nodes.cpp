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
    int findheight(TreeNode* curr,int direction)
    {
        int h=0;
        while(curr)
        {
            h++;
            if(direction==1)
            {
                curr=curr->left;
            }
            else if(direction==2)
            {
               curr=curr->right; 
            }
        }

        return h;
    }
    int countNodes(TreeNode* root) 
    {
        if(!root) return 0;

        int left=findheight(root,1);
        int right=findheight(root,2);

        if(left==right)
        {
            return pow(2,left)-1;
        }
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};