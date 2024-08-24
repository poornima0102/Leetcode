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
        if(sum>=idx){
            output.push_back(idx);
           solve(k-1,sum-idx,output,ans,idx+1);
           output.pop_back();
        }
           solve(k,sum,output,ans,idx+1);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> output;
        vector<vector<int>> ans;
        
        solve(k,n,output,ans,1);
        return ans;
    }
};