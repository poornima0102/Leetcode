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
// class Solution {
// public:
//  void recursionRight(TreeNode* root, int level, vector<int> &res){
//         // Check if the current node is NULL
//         if(root == NULL){
//             return;
//         }
        
//         // Check if the size of the result vector is equal to the current level
//         if(res.size() == level)
//             // If equal, add the value of the current node to the result vector
//             res.push_back(root->val);
            
//             // Recursively call the function for the right child with an increased level
//             recursionRight(root->right, level + 1, res);
            
//             // Recursively call the function for the left child with an increased level
//             recursionRight(root->left, level + 1, res);
//         }
    
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> res;
//         recursionRight(root, 0, res);
//         return res;
//     }
// };


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
      vector<int> ans;
        if (!root) return ans; // Return empty vector if the tree is empty

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size(); // Number of nodes at the current level

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                // If it's the last node in this level, add it to the answer
                if (i == n - 1) {
                    ans.push_back(node->val);
                }

                // Push the left and right children of the node into the queue
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return ans;
    }
};