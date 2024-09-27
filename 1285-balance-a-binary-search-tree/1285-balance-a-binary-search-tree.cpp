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
 void storeInorder(TreeNode* root,vector<int>& inorder){
        if(root==NULL) return;
        storeInorder(root->left,inorder);
        inorder.push_back(root->val);
        storeInorder(root->right,inorder);
    }
    TreeNode* buildBST(vector<int>&inorder,int s,int e){
        if(s>e) return NULL;
        int mid=(s+e)/2;
        int ele=inorder[mid];
        TreeNode* root=new TreeNode(ele);
        root->left=buildBST(inorder,s,mid-1);
        root->right=buildBST(inorder,mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        storeInorder(root,inorder);
        return buildBST(inorder,0,inorder.size()-1);
        

    }
};