#include<cmath>
class Solution{
   
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool, int> isBalancedFast(Node* root)
    {
          if(root == NULL)
        {
           pair<bool, int> p = make_pair(true, 0);
           return p;
        }
        
        pair<int, int> left = isBalancedFast(root->left);
        pair<int, int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        
        bool diff = abs (left.second - right.second) <= 1;
        
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff)
        {
            ans.first = 1;
        }
        else 
        {
            ans.first = 0;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
      
        isBalancedFast(root).first;
    }
}

Time Complexity, O(n) // Because, every node we visit single time