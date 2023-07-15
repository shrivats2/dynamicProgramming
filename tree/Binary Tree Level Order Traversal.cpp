#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define yes cout << "YES"<< "\n";
#define no cout << "NO" << "\n";
#define fr(i, a, b) for(int i = a; i<b; i++)
#define vi vector<ll>
#define pb push_back
#define aa(l,n) ll l[n]; fr(i,0,n) cin>>l[i];
#define av(l, n) vector<ll> l(n); fr(i,0,n) cin>>l[i];

const int mod = 1e9 + 7;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
       vector<vector<int>>ans;
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty())
       {
           int t=q.size();
           vector<int>res;
           while(t--)
           {
               auto i=q.front();
               q.pop();
               if(i!=NULL)
                  res.push_back(i->val);
               if(i!=NULL&&i->left!=NULL)
               {
                   q.push(i->left);
               }
               if(i!=NULL&&i->right!=NULL)
               {
                   q.push(i->right);
               }
           }
           if(res.size()>0)
            ans.push_back(res);
       }
       return ans; 
    }
};

TreeNode* buildTree() 
{
    int val;
    cout << "Enter root value (or -1 for null): ";
    cin >> val;

    if (val == -1)
        return nullptr;

    TreeNode* root = new TreeNode(val);

    cout << "Enter left subtree of " << val << ":\n";
    root->left = buildTree();

    cout << "Enter right subtree of " << val << ":\n";
    root->right = buildTree();

    return root;
}

int main() 
{
    Solution solution;
    TreeNode* root = buildTree();

    vector<vector<int>> result = solution.levelOrder(root);

    cout << "Level Order Traversal:\n";
    for (const auto& level : result) 
    {
        for (int num : level) 
        {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}