#include <iostream>
#include<bits/stdc++.h>
using namespace std;


class node
{
    public:
    
    int data;
    node* left;
    node* right;
    
    node(int val)
    {
        this->data=val;
        this->left=this->right=NULL;
    }
};

bool searchBST(node* &root, int key)
{
    while(root != NULL && root->data == key)
    {
        root = key < root->data ? root->left : root->right;
    }
    
    return root;
}

void printInorder(node* &root)
{
    if(root == NULL)
    {
        return;
    }
    
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
  node* root = new node(5);
    root->left = new node(3);
    root->right = new node(8);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(10);
    
    cout << "Binary Search Tree" << endl;    
    printInorder(root);
    
    int key = 4;
    bool res = searchBST(root, key);
    
    if(res)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    
    return 0;
}