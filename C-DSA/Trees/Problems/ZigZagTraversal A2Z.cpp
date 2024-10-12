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

vector<vector<int>> zigzag(node* root)
{
    vector<vector<int>> result;
    
    if(root == NULL)
    {
        return result;
    }
    
    queue<node*> nodeQueue;
    nodeQueue.push(root);
    
    bool leftToright = true;
    
    while(!nodeQueue.empty())
    {
        int size = nodeQueue.size();
        vector<int> row(size);
        
        for(int i=0;i<size;i++)
        {
            node* Node = nodeQueue.front();
            nodeQueue.pop();
            
            int index = leftToright ? i : (size-1-i);
            
            row[index] = Node->data;
            
            if(Node->left)
            {
                nodeQueue.push(Node->left);
            }
            
            if(Node->right)
            {
                nodeQueue.push(Node->right);
            }
        }
        
        leftToright = !leftToright;
        result.push_back(row);
    }
    return result;
}

void printResult(const vector<vector<int>>& result )
{
    for(const auto& row:result)
    {
        for(int val:row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<vector<int>> result = zigzag(root);
    printResult(result);

    return 0;
}