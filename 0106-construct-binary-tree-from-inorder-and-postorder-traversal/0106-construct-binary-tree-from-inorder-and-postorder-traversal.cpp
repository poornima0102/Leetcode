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
TreeNode* helper(vector<int>& postorder, int &postEnd,
            vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
                // Base case: If the start indices 
                // exceed the end indices, return NULL
                if(postEnd<0 || inStart > inEnd){
                    return NULL;
                }
                
                // Create a new TreeNode with value at the current postorder index
                TreeNode* root = new TreeNode(postorder[postEnd--]);
                
                // Find the index of the current root value in the inorder traversal
                int inRoot = inMap[root->val];
                
                // Recursively build the right subtree
                root->right = helper(postorder, postEnd, inorder, inRoot + 1, inEnd, inMap);
                
                // Recursively build the left subtree
                root->left = helper(postorder, postEnd, inorder, inStart, inRoot - 1, inMap);
                
              
                // Return the current root node
                return root;
            }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;

         for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
    int postEnd = postorder.size()-1;
    return helper(postorder,postEnd,inorder,0,inorder.size()-1,inMap);
    }
};