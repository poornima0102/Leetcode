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
    void allPaths(TreeNode* root, int targetSum,vector<vector<int>> &ans,vector<int> path){
        if(!root) return;
        if(root->left==NULL && root->right==NULL){
            
            if(targetSum==root->val){
                path.push_back(root->val);
                ans.push_back(path);
                return;
            }
            return;
        }
        path.push_back(root->val);
        allPaths(root->left,targetSum-root->val,ans,path);
        
        allPaths(root->right,targetSum-root->val,ans,path);
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        allPaths(root,targetSum,ans,path);
        return ans;
    }
};