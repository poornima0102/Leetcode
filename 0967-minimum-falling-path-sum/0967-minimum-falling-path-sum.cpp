class Solution {
public:
    // int solve(vector<vector<int>>& matrix,int n,int i,int j){
    //     if(j>=n || j<0){
    //         return INT_MAX;
    //     }
    //     else if(i==n-1 ){
    //     return matrix[i][j];
    //     }
    //     int sum=matrix[i][j]+min(solve(matrix,n,i+1,j-1),min(solve(matrix,n,i+1,j),solve(matrix,n,i+1,j+1)));
    //     return sum;
    // }
    int solveTab(vector<vector<int>>& matrix,int n){
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0)
                dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                else if(j==n-1)
                dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                else
                dp[i][j]=matrix[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // int ans=INT_MAX;
        // for(int j=0;j<n;j++){
        //    ans=min(ans,solve(matrix,n,0,j));
        // }
        // return ans;
        return solveTab(matrix,n);
    }
};