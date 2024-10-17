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
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insert(node* &root, int data)
{
   node* temp = new node(data);
   
   if(root == NULL)
   {
       return temp;
   }
   
   node* parent = NULL;
   node* curr = root;
   
   while(curr != NULL)
   {
       parent = curr;
       if(curr->data > data)
       {
           curr = curr->left;
       }
       else if(curr->data < data)
       {
           curr = curr->right;
       }
       else
       {
        return root;   
       }
   }
   
   if(parent->data > data)
   {
       parent->left = temp;
   }
   else
   {
       parent->right = temp;
   }
   return root;
}

void printInorder(node* &root)
{
    if(!root)
    {
        return;
    }
    
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    node* root = new node(1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);

    printInorder(root);

    return 0;
}