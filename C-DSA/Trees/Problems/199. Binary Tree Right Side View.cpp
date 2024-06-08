/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output; // Output store karne ke liye
        queue<TreeNode*> q; // Queue for level order traversal
        q.push(root); // Root node ko queue me daalo
        if(!root) return output; // Agar root null hai, toh empty output return karo
        
        while(!q.empty()) // Jab tak queue khali nahi hoti
        {
            vector<int> helper; // Temporary helper vector
            int n = q.size(); // Current level ke nodes ki count
           
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front(); // Queue ke front se node lo
                q.pop(); // Us node ko queue se hatao
                helper.push_back(node->val); // Node ke value ko helper me daalo
                if(node->left) q.push(node->left); // Left child ko queue me daalo
                if(node->right) q.push(node->right); // Right child ko queue me daalo
            }
            output.push_back(helper[n-1]); // Helper ke last element ko output me daalo
        }
        return output; // Final output return karo
    }
};
