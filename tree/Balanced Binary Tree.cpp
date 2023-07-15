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
    bool isBalanced(TreeNode* root) 
    {
        function<int(TreeNode*)> helper = [&](TreeNode* curr) 
        {
            if (!curr)
                return 0;

            int leftHeight = helper(curr->left);
            if (leftHeight == -1)
                return -1;
            int rightHeight = helper(curr->right);
            if (rightHeight == -1)
                return -1;

            if (abs(leftHeight - rightHeight) > 1)
                return -1;

            return max(rightHeight, leftHeight) + 1;
        };

        return helper(root) != -1;
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

    bool balanced = solution.isBalanced(root);

    if (balanced)
        cout << "The tree is balanced." << "\n";
    else
        cout << "The tree is not balanced." << "\n";

    return 0;
}