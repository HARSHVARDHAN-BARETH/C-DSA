#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val)
    {
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};


void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

node* insertIntoBST(node* root, int val)
{
    if(root == NULL)
    {
        root = new node(val);
        return root;
    }
    
    if(val > root->data)
    {
        root->right = insertIntoBST(root->right, val);
    }
    else
    {
        root->left = insertIntoBST(root->left, val);
    }
    return root;
}

void takeInput(node* &root)
{
    int data;
    cin >> data;
    
    while(data != -1)
    {
       root = insertIntoBST(root, data);
        cin >> data;
    }
}
void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

int main()
{
    node* root = NULL;
    
    cout << "Enter data to create BST" << endl;
    takeInput(root);
    
    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    
    cout << "Printing InOrder" << endl;
    inorder(root);
    
    cout << "Printing preorder" << endl;
    preorder(root);
    
    cout << "Printing postorder" << endl;
    postorder(root);

    return 0;
}

