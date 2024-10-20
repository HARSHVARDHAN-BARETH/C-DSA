#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    
    node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

int maxValue(node* &root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    
    return max({maxValue(root->left),
        maxValue(root->right)
    });
}

int minValue(node* &root)
{
    if(root == NULL)
    {
        return INT_MAX;
    }
    
    return min({minValue(root->left),
        minValue(root->right)
    });
    
}

bool isBST(node* &root)
{
    if(root == NULL)
    {
        return true;
    }
    
    if(root->left!=NULL && maxValue(root->left)>=root->data)
    {
        return false;
    }
    
    if(root->right!=NULL && minValue(root->right)<=root->data)
    {
        return false;
    }
    return isBST(root->left) && isBST(root->right);
}

int main()
{
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);

    if(isBST(root))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}