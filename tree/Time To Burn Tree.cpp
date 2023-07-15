/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here

    unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>mp;
    BinaryTreeNode<int>*s;

    queue<BinaryTreeNode<int>*>q;
    queue<pair<BinaryTreeNode<int>*,int>>q1;
    q.push(root);

    while(!q.empty())
    {
        auto i=q.front();
        q.pop();

        if(i->data==start) s=i;

        if(i->left)
        {
            mp[i->left]=i;
            q.push(i->left);
        }

        if(i->right)
        {
            mp[i->right]=i;
            q.push(i->right);
        }
    }

   
    q1.push({s,0});
    unordered_map<BinaryTreeNode<int>*,int>mp1;
    mp1[s]++;
    int ans=0;

    while(!q1.empty())
    {
        auto i=q1.front();
        int t=q1.size();
        ans=i.second;

        while(t--)
        {
            auto i=q1.front();
            q1.pop();
            int a=i.second;
           if(i.first->left&&(mp1.find(i.first->left)==mp1.end()))
            {
              q1.push({i.first->left,a+1});
              mp1[i.first->left]++;  
            }
             if(i.first->right&&(mp1.find(i.first->right)==mp1.end()))
            {
              q1.push({i.first->right,a+1});
               mp1[i.first->right]++;    
            }
            if(mp[i.first]>0&&(mp1.find(mp[i.first])==mp1.end()))
            {
             q1.push({mp[i.first],a+1});
              mp1[mp[i.first]]++;   
            }
        }
        
    }

    return ans;
}
