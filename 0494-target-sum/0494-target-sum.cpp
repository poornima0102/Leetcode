class Solution {
public:
// int solve(vector<int>& nums, int target,int i){
//     if(i>=nums.size()){
//         if(target==0){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     int ans1=0,ans2=0;

//         ans1=solve(nums,target-nums[i],i+1);
//         ans2=solve(nums,target+nums[i],i+1);
    
//     return ans1+ans2;
// }  
    int solveTab(vector<int>& nums, int sum,int n){
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        if(nums[0]<=sum){
            dp[0][nums[0]]=1;
        }
        dp[0][0]=1;
        if(nums[0]==0){
            dp[0][0]=2;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int inc=0,exc=0;
                if(nums[i]<=j){
                    inc=dp[i-1][j-nums[i]];
                }
                exc=dp[i-1][j];
                dp[i][j]=inc+exc;
            }
        }
        return dp[n-1][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // return solve(nums,target,0);
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        int subsetSum=(total+target)/2;
        if((total+target)%2!=0 ||target>total) return 0;
        if(subsetSum>total || subsetSum<0) return 0;
        return solveTab(nums,(total+target)/2,n);
    }
};