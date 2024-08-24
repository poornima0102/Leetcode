class Solution {
public:
    void solve(int k, int sum,vector<int> output,vector<vector<int>> & ans,int idx){
        if(k==0 && sum==0){
            ans.push_back(output);
            return;
        }
        if(idx>9){
           return;
        }
          solve(k,sum,output,ans,idx+1);
        if(sum>=idx && k!=0){
            output.push_back(idx);
           solve(k-1,sum-idx,output,ans,idx+1);
           output.pop_back();
        }
         
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> output;
        vector<vector<int>> ans;
        
        solve(k,n,output,ans,1);
        return ans;
    }
};