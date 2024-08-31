class Solution {
public:
    // int solveRec(vector<vector<int>>& grid,int m,int n){
    //     if(m<0 || n<0){
    //         return INT_MAX;
    //     }
    //     if(m==0 && n==0){
    //         return grid[0][0];
    //     }
        
    //     int sum1=grid[m][n]+min(solveRec(grid,m-1,n),solveRec(grid,m,n-1));
        
    //     return sum1;
    // }

    // int solveMem(vector<vector<int>>& grid,int m,int n,vector<vector<int>> &dp){
    //     if(m<0 || n<0){
    //         return INT_MAX;
    //     }
    //     if(m==0 && n==0){
    //         return grid[0][0];
    //     }
    //     if(dp[m][n]!=0){
    //         return dp[m][n];
    //     }
    //     dp[m][n]=grid[m][n]+min(solveMem(grid,m-1,n,dp),solveMem(grid,m,n-1,dp));
        
    //     return dp[m][n];
    // }

    int solveTab(vector<vector<int>>& grid,int m,int n){
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int j=1;j<n;j++){
            dp[0][j]=grid[0][j]+dp[0][j-1];
        }
        for(int i=1;i<m;i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                // if(j-1>=0)
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
                // else
                // dp[i][j]=grid[i][j]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // return solveRec(grid,m-1,n-1);
        // vector<vector<int>>dp(m,vector<int>(n,0));
        // return solveMem(grid,m-1,n-1,dp);
        return solveTab(grid,m,n);
    }
};