class Solution {
public:

    void solve(vector<int>& nums,vector<int>output,vector<vector<int>>&ans,int i){
       
        if(i>=nums.size()){
           ans.push_back(output);
           return ;
        }
        //include
        output.push_back(nums[i]);
        solve(nums,output,ans,i+1);
        output.pop_back();
        //skip
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        solve(nums,output,ans,i+1);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> output;
        vector<vector<int>> ans;
        solve(nums,output,ans,0);
        return ans;
    }
};