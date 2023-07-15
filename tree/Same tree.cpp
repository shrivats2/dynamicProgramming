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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});
        while (!st.empty()) 
        {
            auto [curr, curr1] = st.top();
            st.pop();
            if (!curr && !curr1) 
                 continue;
            if (!curr || !curr1 || curr->val != curr1->val) 
                 return false;
            st.push({curr->left, curr1->left});
            st.push({curr->right, curr1->right});
        }
        return true;  
    }
};