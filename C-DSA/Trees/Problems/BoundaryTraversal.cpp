#include <iostream>
#include <vector>
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

bool isLeaf(node* root) {
    return !root->left && !root->right;
}

void addLeafBoundary(node* root, vector<int>& res) {
    node* curr = root->left;

    while (curr) {
        if (!isLeaf(curr)) {
            res.push_back(curr->data);
        }

        if (curr->left) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}

void addRightBoundary(node* root, vector<int>& res) {
    node* curr = root->right;
    vector<int> temp;

    while (curr) {
        if (!isLeaf(curr)) {
            temp.push_back(curr->data);
        }

        if (curr->right) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    for (int i = temp.size() - 1; i >= 0; i--) { // Reverse to get correct order
        res.push_back(temp[i]);
    }
}

void addLeaves(node* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data); // Missing semicolon fixed here
        return;
    }

    if (root->left) {
        addLeaves(root->left, res);
    }
    if (root->right) {
        addLeaves(root->right, res);
    }
}

vector<int> printBoundary(node* root) {
    vector<int> res;

    if (!root) {
        return res;
    }

    if (!isLeaf(root)) {
        res.push_back(root->data);
    }

    addLeafBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}

void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> result = printBoundary(root);
    printResult(result);

    return 0;
}
