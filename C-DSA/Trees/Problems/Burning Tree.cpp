#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
  Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {
      Node* res = nullptr;
      queue<Node*> q;
      q.push(root);
      nodeToParent[root] = nullptr;
      
      while(!q.empty()) {
          Node* front = q.front();
          q.pop();
          
          if(front->data == target) {
              res = front;
          }
          
          if(front->left) {
              nodeToParent[front->left] = front;
              q.push(front->left);
          }
          
          if(front->right) {
              nodeToParent[front->right] = front;
              q.push(front->right);
          }
      }
      return res; // Add return statement
  }
  
  int burnTree(Node* root, map<Node*, Node*> &nodeToParent) {
      map<Node*, bool> visited;
      queue<Node*> q;
      
      q.push(root);
      visited[root] = true;
      
      int ans = 0;
      
      while(!q.empty()) {
          bool flag = false;
          int size = q.size();
          for(int i = 0; i < size; i++) {
              Node* front = q.front();
              q.pop();
              
              if(front->left && !visited[front->left]) {
                  flag = true;
                  q.push(front->left);
                  visited[front->left] = true;
              }
              
              if(front->right && !visited[front->right]) {           
                  flag = true;
                  q.push(front->right);
                  visited[front->right] = true;
              }
              
              if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                  flag = true;
                  q.push(nodeToParent[front]);
                  visited[nodeToParent[front]] = true;
              }
          }
          if(flag) {
              ans++;
          }
      }
      return ans;
  }
  
  int minTime(Node* root, int target) {
      map<Node*, Node*> nodeToParent;
      Node* targetNode = createParentMapping(root, target, nodeToParent);
      
      if (targetNode == nullptr) return 0; // Check if the target node is found
      
      int ans = burnTree(targetNode, nodeToParent);
      return ans;
  }
};

// For testing purposes
int main() {
    Solution solution;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    int target = 5;
    cout << "Minimum time to burn the tree: " << solution.minTime(root, target) << endl;
    
    // Free allocated memory (optional for small test cases, recommended for larger applications)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
