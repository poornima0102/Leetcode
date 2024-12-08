/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL)  {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, TreeNode* target,unordered_map<TreeNode*,TreeNode*>&parent_track ){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        markParent(root,target,parent_track);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int dist=0;
        while(!q.empty()){
            int n=q.size();
            if(dist++==k) break;
            
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right]=true;
                
                }
                if(parent_track[temp] && !visited[parent_track[temp]]){
                    q.push(parent_track[temp]);
                    visited[parent_track[temp]]=true;
                }
        }
    }
    vector<int> result;
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        result.push_back(temp->val);
    }
    return result;
    }
};