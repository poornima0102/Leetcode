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
TreeNode* helper(vector<int>& preorder, int &preStart,
            vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
                // Base case: If the start indices 
                // exceed the end indices, return NULL
                if(preStart>=preorder.size() || inStart > inEnd){
                    return NULL;
                }
                
                // Create a new TreeNode with value at the current preorder index
                TreeNode* root = new TreeNode(preorder[preStart++]);
                
                // Find the index of the current root value in the inorder traversal
                int inRoot = inMap[root->val];
                
                // Calculate the number of elements in the left subtree
                
                // Recursively build the left subtree
                root->left = helper(preorder, preStart, inorder, inStart, inRoot - 1, inMap);
                
                // Recursively build the right subtree
                root->right = helper(preorder, preStart, inorder, inRoot + 1, inEnd, inMap);
                
                // Return the current root node
                return root;
            }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;

         for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
    int preStart = 0;
        return helper(preorder, preStart,inorder, 0, inorder.size()-1, inMap);
    }
};