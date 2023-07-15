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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int mx=0;
        function<int(TreeNode*)> helper = [&](TreeNode* curr) 
        {
            if (!curr)
                return 0;

            int leftHeight = helper(curr->left);
            int rightHeight = helper(curr->right);

            mx=max(mx,leftHeight+rightHeight);

            return max(rightHeight, leftHeight) + 1;
        };

        helper(root);

        return mx;
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

    int diameter = solution.diameterOfBinaryTree(root);

    cout << "The diameter of tree is "<< diameter<< "\n";

    return 0;
}