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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q; //node->{row,col}
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>> mp; //col->row->values

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            TreeNode* node=front.first;
            auto coordinates=front.second;
            int row=coordinates.first;
            int col=coordinates.second;
            mp[col][row].insert(node->val);

            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }

        }
        //store final vertcal order into ans vector
        for(auto it:mp){
            auto& colmap=it.second;
            vector<int>vLine;
            for(auto colmapIt:colmap){
                auto& mset=colmapIt.second;
                vLine.insert(vLine.end(),mset.begin(),mset.end());
            }
            ans.push_back(vLine);
        }
    return ans;
    }
};