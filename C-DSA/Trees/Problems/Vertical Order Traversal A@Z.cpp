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

vector<vector<int>> findVertical(node* root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<node*, pair<int,int>>> todo;
    
    todo.push({root, {0,0}});
    
    while(!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        node* temp = p.first;
        
        int x = p.second.first;
        int y = p.second.second;
        
        nodes[x][y].insert(temp->data);
        
        if(temp->left)
        {
            todo.push({
                temp->left,
                {
                    x-1,
                    y+1
                }
            });
        }
        
        if(temp->right)
        {
            todo.push({
                
                temp->right,
                {
                    x+1,
                    y+1
                }
            });
        }
    }
    
    vector<vector<int>> ans;
    
    for(auto p:nodes)
    {
       vector<int> col;
       for(auto q:p.second)
       {
           col.insert(col.end(),q.second.begin(),q.second.end());
       }
       ans.push_back(col);
    }
    return ans;
}

void printResult(const vector<vector<int>>& result)
{
    for(auto level:result)
    {
        for(auto node:level)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(10);
    root->left->left->right = new node(5);
    root->left->left->right->right = new node(6);
    root->right = new node(3);
    root->right->right = new node(10);
    root->right->left = new node(9);
    
    vector<vector<int>> verticalTraversal = findVertical(root);
    printResult(verticalTraversal);
    
    return 0;
}