#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.

    if(!root) return ;
    int val=0;

    if(root->left)
    {
      val+=root->left->data;
    }
    if(root->right)
    {
        val+=root->right->data;
    }

    if(root->data<=val)
    {
        root->data=val;
    }
    else
    {
        if(root->left)
        {
            root->left->data=root->data;
        }
        if(root->right)
        {
            root->right->data=root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);
    
    int sum=0;
    if(root->left)
    {
        sum+=root->left->data;
    }
    if(root->right)
    {
        sum+=root->right->data;
    }
    if(root->left||root->right)
    {
        root->data=sum;
    }   

}  