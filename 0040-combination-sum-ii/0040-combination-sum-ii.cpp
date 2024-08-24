
class Solution {
public:
    void solve(vector<int>& candidates, int target,int i,vector<int> output,vector<vector<int>>&ans){
        int n=candidates.size();
        if(target==0){
            sort(output.begin(),output.end());
            ans.push_back(output);
            return;
        }
        if(i>=n  ){
           return ;
          
        }

        
        if(target>=candidates[i]){
            output.push_back(candidates[i]);
          
            solve(candidates,target-candidates[i],i+1,output,ans);
            output.pop_back();
        }
        while(i+1<n && candidates[i]==candidates[i+1]) i++;
        solve(candidates,target,i+1,output,ans);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         sort(candidates.begin(),candidates.end());
        vector<int> output;
        vector<vector<int>> ans;
        solve(candidates,target,0,output,ans);
        return ans;
    }
};