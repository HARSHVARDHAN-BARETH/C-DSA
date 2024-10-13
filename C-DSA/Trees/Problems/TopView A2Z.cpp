#include <iostream>
#include <vector>
#include <map>
#include <queue>
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

vector<int> topView(node* &root) {
    vector<int> ans;
    
    if (root == NULL) {
        return ans;
    }
    
    map<int, int> mpp; // map to store the first node at each horizontal distance
    queue<pair<node*, int>> q; // queue to hold nodes along with their horizontal distance
    q.push({root, 0});
    
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        node* Node = it.first;
        int line = it.second;

        // Insert the first node at each horizontal distance
        if (mpp.find(line) == mpp.end()) {
            mpp[line] = Node->data;
        }
        
        if (Node->left != NULL) {
            q.push({Node->left, line - 1});
        }
        if (Node->right != NULL) {
            q.push({Node->right, line + 1});
        }
    }
    
    // Populate the ans vector from the map in sorted order of horizontal distance
    for (auto it : mpp) {
        ans.push_back(it.second);
    }
    
    return ans;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> result = topView(root);
    for (auto node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
