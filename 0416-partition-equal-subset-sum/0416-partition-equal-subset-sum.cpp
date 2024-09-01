// class Solution {
// public:
//     // bool solveTD(vector<int>& nums,int n,vector<vector<int>>& dp,int capacity){
//     //     if(n==0){
//     //         if(nums[n]==capacity){
//     //             return true;
//     //         }
//     //         else{
//     //             return false;
//     //         }
//     //     }
//     //     if(dp[n][capacity]!=-1){
//     //         return dp[n][capacity];
//     //     }
//     //     int include=0;
//     //     if(nums[n]<=capacity){
//     //         include=solveTD(nums,n-1,dp,capacity-nums[n]);
//     //     }
//     //     int exclude=solveTD(nums,n-1,dp,capacity);
//     //     return dp[n][capacity]=include||exclude;

//     // }
//     bool solveBU(vector<int>& nums,int n,int capacity){
//         vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
//         for(int wt=0;wt<=capacity;wt++){
//             if(nums[0]==wt) 
//             dp[0][wt]= true;
//             else
//             dp[0][wt]= false;
//         }
//         dp[0][0]=true;
//         for(int i=1;i<n;i++){
//             for(int wt=0;wt<=capacity;wt++){
//                 int include=0;
//                 if(nums[i]<=wt){
//                    include=dp[i-1][wt-nums[i]];
//                 }
//                 int exclude=dp[i-1][wt];
//                 dp[i][wt]=include||exclude;
//             }
//         }
//         return dp[n-1][capacity];
//     }

//     //    bool solveSO(vector<int>& nums,int n,int capacity){
//     //     vector<int> prev(capacity+1,-1);
//     //     vector<int> curr(capacity+1,-1);
//     //     for(int wt=0;wt<=capacity;wt++){
//     //         if(nums[0]==wt) 
//     //         prev[wt]= true;
//     //         else
//     //         prev[wt]= false;
//     //     }
//     //     for(int i=1;i<n;i++){
//     //         for(int wt=0;wt<=capacity;wt++){
//     //             int include=0;
//     //             if(nums[i]<=wt){
//     //                include=prev[wt-nums[i]];
//     //             }
//     //             int exclude=prev[wt];
//     //             curr[wt]=include||exclude;
//     //         }
//     //         prev=curr;
//     //     }
//     //     return prev[capacity];
//     // }

//     //     bool solveSO2(vector<int>& nums,int n,int capacity){
       
//     //     vector<int> curr(capacity+1,-1);
//     //     for(int wt=0;wt<=capacity;wt++){
//     //         if(nums[0]==wt) 
//     //         curr[wt]= true;
//     //         else
//     //         curr[wt]= false;
//     //     }
//     //     for(int i=1;i<n;i++){
//     //         for(int wt=capacity;wt>=0;wt--){
//     //             int include=0;
//     //             if(nums[i]<=wt){
//     //                include=curr[wt-nums[i]];
//     //             }
//     //             int exclude=curr[wt];
//     //             curr[wt]=include||exclude;
//     //         }
            
//     //     }
//     //     return curr[capacity];
//     // }
//     bool canPartition(vector<int>& nums) {
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//         }
//         if(sum%2!=0)
//         return false;
//         int n=nums.size();
//         int capacity=sum/2;
//         // vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
//         // return solveTD(nums,n-1,dp,capacity);
//         return solveBU(nums,n,capacity);
//        // return solveSO2(nums,n,capacity);
//     }
// };


class Solution {
public:
//     bool solve(vector<int>& nums, int sum, int index, vector<vector<int>> & dp) {
//         if(sum == 0) return true;
//         if(index < 0 || sum < 0) return false;

//         if(dp[index][sum] != -1) return dp[index][sum];

//         return dp[index][sum] = solve(nums, sum, index - 1, dp) || solve(nums, sum - nums[index], index - 1, dp);
//     }
int solveTab(vector<int>nums, int sum,int n){
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(nums[0]<=sum)
        dp[0][nums[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                int inc=0;
                if(j>=nums[i]){
                 inc=dp[i-1][j-nums[i]];
                }
       
                int exc=dp[i-1][j];
            
      
                dp[i][j] =inc||exc;
            }
            
        }
        return dp[n-1][sum];
}
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int num: nums) sum += num;

        if(sum % 2 == 1) return false;

        sum /= 2;

//         vector<vector<int>> dp(n + 1, vector<int> (sum + 1, -1));

//         return solve(nums, sum, n - 1, dp);
return solveTab(nums,sum,n);
    }
};


