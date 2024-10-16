#include <iostream>
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

int florBST(node* &root, int key)
{
    int flor = -1;
    
    while(root)
    {
        if(root->data == key)
        {
            flor = root->data;
            return flor;
        }
        
        if(key > root->data)
        {
            flor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return flor;
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
    root->right->right = new node(14);

    cout << "Binary Search Tree" << endl;
    printInorder(root);
    
    int key = 8;
    int res = florBST(root, key);
    
    cout << "\nFloar of " << key << " is at " << res;
    
    return 0;
}