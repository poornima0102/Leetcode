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
    int maxVal(TreeNode* root){
    TreeNode* temp=root;
    while(temp->right!=nullptr){
        temp=temp->right;
    }
    return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
           if(root->left==NULL && root->right==NULL){
            return NULL;
           }
           else if(root->left==NULL && root->right!=NULL){
            TreeNode* child=root->right;
            return child;
           }
           else if(root->left!=NULL && root->right==NULL){
            TreeNode* child=root->left;
            return child;
           }
           else{
            int inPre=maxVal(root->left);
            root->val=inPre;
            root->left=deleteNode(root->left,inPre);
            return root;
           }
        }
        else if(root->val>=key){
            root->left=deleteNode(root->left,key);
        }
        else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};