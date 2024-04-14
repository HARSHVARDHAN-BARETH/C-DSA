#include <iostream>
#include <queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    
    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree()
{
    int data;
    cout << "Enter the data (or -1 to stop): ";
    cin >> data;
    
    if (data == -1) {
        return NULL; // Base case: stop building the tree
    }
    
    node* root = new node(data);
    
    cout << "Enter the data for the left child of " << data << ": \n" ;
    root->left = buildTree();
    
    cout << "Enter the data for the right child of " << data << ": \n";
    root->right = buildTree();
    
    return root;
}

void levelOrderTraversal(node* root)
{
    if (root == NULL)
        return;
    
    queue<node*> q;
    q.push(root);
    
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }else{
                    cout << temp->data << " ";

             if (temp->left)
        {
            q.push(temp->left);
        }
        
        if (temp->right)
        {
            q.push(temp->right);
        }
        }
        
       
    }
}

int main()
{
    node* root = NULL;
    root = buildTree();
    cout << "Printing the level order traversal: \n";
    levelOrderTraversal(root);
    
    return 0;
}
