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

void recursionRight(node* &root, int level, vector<int> &res)
{
    if(root == NULL)
    {
        return;
    }
    
    if(res.size() == level)
    {
        res.push_back(root->data);
        
        recursionRight(root->right,level+1,res);
        recursionRight(root->left, level+1, res);
    }
}

vector<int> rightSideView(node* &root)
{
    vector<int> res;
    
    recursionRight(root,0,res);
    
    return res;
}

void recursionLeft(node* &root, int level, vector<int> &res)
{
    if(root == NULL)
    {
        return;
    }
    
    if(res.size() == level)
    {
        res.push_back(root->data);
        
        recursionLeft(root->left,level+1,res);
        recursionLeft(root->right, level+1, res);
    }
}

vector<int> leftSideView(node* &root)
{
    vector<int> res;
    
    recursionLeft(root,0,res);
    
    return res;
}


int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(10);
    root->left->left->right = new node(5);
    root->left->left->right->right = new node(6);
    root->right = new node(3);
    root->right->right = new node(10);
    root->right->left = new node(9);

    vector<int> result1 = rightSideView(root);
    for(auto val1:result1)
    {
        cout << val1 << " ";
    } cout << endl;
    
    vector<int> result2 = leftSideView(root);
    for(auto val2:result2)
    {
        cout << val2 << " ";
    } cout << endl;
   

    return 0;
}