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
    int ans=0;
    void pathFromOneRoot(TreeNode* root, long long targetSum){
        if(!root) return;
        if(root->val == targetSum){
            ans++;
        }
        pathFromOneRoot(root->left,targetSum-root->val);
        pathFromOneRoot(root->right,targetSum-root->val);
    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(root){
            pathFromOneRoot(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }
};