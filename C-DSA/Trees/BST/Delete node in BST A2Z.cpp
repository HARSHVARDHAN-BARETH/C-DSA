#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to find the inorder successor (smallest node in the right subtree)
node* getSuccessor(node* curr) {
    curr = curr->right; // Move to right subtree
    // Go to the leftmost node in the right subtree
    while (curr != NULL && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

node* delNode(node* &root, int x) {
    if (root == NULL) {
        return root; // Base case: If the root is NULL
    }

    // Traverse the tree
    if (root->data > x) {
        root->left = delNode(root->left, x); // Move to left subtree
    }
    else if (root->data < x) {
        root->right = delNode(root->right, x); // Move to right subtree
    }
    else { // Node to be deleted found
        // Case 1: No left child
        if (root->left == NULL) {
            node* temp = root->right; // Store the right child
            delete root;              // Delete current node
            return temp;              // Return the right child to link with parent
        }

        // Case 2: No right child
        if (root->right == NULL) {
            node* temp = root->left; // Store the left child
            delete root;             // Delete current node
            return temp;             // Return the left child to link with parent
        }

        // Case 3: Two children
        // Get the inorder successor (smallest in the right subtree)
        node* succ = getSuccessor(root);

        // Replace the current node's data with successor's data
        root->data = succ->data;

        // Delete the inorder successor
        root->right = delNode(root->right, succ->data);
    }
    return root;
}

// Function to perform inorder traversal (prints tree in sorted order)
void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    // Creating a binary search tree
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->right->left = new node(12);
    root->right->right = new node(18);
    
    int x = 15; // Node to be deleted
    
    // Deleting the node with value 15
    root = delNode(root, x);
    
    // Printing the inorder traversal of the updated tree
    inorder(root);
    
    return 0;
}
