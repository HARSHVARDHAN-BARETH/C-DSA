#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        this->data = val;
        this->left = this->right = NULL;
    }
};

bool isSymmetricUtil(node* root1, node* root2)
{
    if(root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }
    
    return (root1->data == root2->data) && isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left);
}

bool isSymmetric(node* root)
{
    if(!root)
    {
        return true;
    }
    
    return isSymmetricUtil(root->left, root->right);
}

void printInorder(node* root)
{
    if(!root)
    {
        return;
    }
    
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->right->right = new node(6);
    root->left->right = new node(4);
    root->right->left = new node(4);

    printInorder(root);

    bool res;
    res = isSymmetric(root);
    
    if(res)
    {
        cout << "Tree is Symmetric" << endl;
    }
    else
    {
        cout << "Tree is not Symmetric" << endl;
    }

    return 0;
}