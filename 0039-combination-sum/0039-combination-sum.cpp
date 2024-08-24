class Solution {
public:
    void solve(vector<int>& candidates, int target,int i,vector<int> output,vector<vector<int>>&ans){
        int n=candidates.size();
        
        if(i>=n  ){
           if(target==0){
            ans.push_back(output);
            return;
        }
          return;
        }

        solve(candidates,target,i+1,output,ans);
        if(target>=candidates[i]){
            output.push_back(candidates[i]);
          
            solve(candidates,target-candidates[i],i,output,ans);
        }
        
         
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> output;
        vector<vector<int>> ans;
        solve(candidates,target,0,output,ans);
        return ans;
    }
};