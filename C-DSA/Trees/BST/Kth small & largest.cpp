#include <iostream>
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

void inorder(node* &root, vector<int> &arr)
{
    if(!root)
    {
        return;
    }
    
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
    
    return;
}

pair<int, int> findKth(node* &root, int key)
{
     vector<int> arr;
     
     inorder(root, arr);
     
     int k = key;
     
     int kthsmalest = arr[k-1];
     int kthlargest = arr[arr.size()-k];
     
     return {kthsmalest, kthlargest};
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

int main() {
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(13);
    root->left->left = new node(3);
    root->left->left->left = new node(2);
    root->left->left->right = new node(4);
    root->left->right = new node(6);
    root->left->right->right = new node(9);
    root->right->left = new node(11);
    root->right->right = new node(14);;

    cout << "Binary Search Tree" << endl;
    printInorder(root);
    
    int key = 3;
    pair<int, int> res = findKth(root, key);
    
    cout << "\nKth smallest " << res.first << " and Kth largest " << res.second;
    
    return 0;
}