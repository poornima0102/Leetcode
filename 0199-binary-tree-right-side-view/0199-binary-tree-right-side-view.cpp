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
 void recursionRight(TreeNode* root, int level, vector<int> &res){
        // Check if the current node is NULL
        if(root == NULL){
            return;
        }
        
        // Check if the size of the result vector is equal to the current level
        if(res.size() == level)
            // If equal, add the value of the current node to the result vector
            res.push_back(root->val);
            
            // Recursively call the function for the right child with an increased level
            recursionRight(root->right, level + 1, res);
            
            // Recursively call the function for the left child with an increased level
            recursionRight(root->left, level + 1, res);
        }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursionRight(root, 0, res);
        return res;
    }
};