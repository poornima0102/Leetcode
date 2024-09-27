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
    bool solve(TreeNode* root,long long int lowerBound,long long int upperBound){
        if(root==NULL) return true;

        if(root->val > lowerBound && root->val < upperBound){
            //check left subtree is valid or not
            bool leftAns=solve(root->left,lowerBound,root->val);
            //check right subtree is valid or not
            bool rightAns=solve(root->right,root->val,upperBound);
            return leftAns && rightAns; //both should be in range
        }else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        
        long long int lowerBound=-4294967296;
        long long int upperBound=4294967296;
        bool ans=solve(root,lowerBound,upperBound);
        return ans;
    }
};