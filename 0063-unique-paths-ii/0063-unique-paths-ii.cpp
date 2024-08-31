class Solution {
public:
    // int solve(vector<vector<int>>& obstacleGrid,int m,int n,int i,int j){
    //     if(i>=m || j>=n){
    //         return 0;
    //     }
    //     int count=0;
    //     if(obstacleGrid[i][j]==1 ){
    //         return 0;
    //     }
    //      if(i==m-1 && j==n-1 && obstacleGrid[i][j]!=1){
    //         return 1;
    //     }
        
    //      count=solve(obstacleGrid,m,n,i+1,j)+solve(obstacleGrid,m,n,i,j+1);
        
    //  return count;
    // }
    //   int solveMem(vector<vector<int>>& obstacleGrid,int m,int n,int i,int j,vector<vector<int>> &dp){
    //     if(i>=m || j>=n){
    //         return 0;
    //     }
        
    //      if(i==m-1 && j==n-1 && obstacleGrid[i][j]!=1){
    //         return 1;
    //     }
    //     if(obstacleGrid[i][j]==1){
    //         return 0;
    //     }
    //     if(dp[i][j]!=0){
    //         return dp[i][j];
    //     }
    //     dp[i][j] =solveMem(obstacleGrid,m,n,i+1,j,dp)+solveMem(obstacleGrid,m,n,i,j+1,dp);
            
        
    //  return dp[i][j];
    // }

    int solveTab(vector<vector<int>>& obstacleGrid,int m,int n){
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]!=1){
              dp[i][0]=1;
            }
            else{
                dp[i][0]=0;
                break;
            }
        }
        for(int j=0;j<n;j++){
            if(obstacleGrid[0][j]!=1){
              dp[0][j]=1;
            }
            else{
                dp[0][j]=0;
                break;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]!=1)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else
                dp[i][j]=0;
            }
        }
        return dp[m-1][n-1];
    }
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(obstacleGrid[i][j]==1) dp[i][j]=0;
    //             else if(i==0 && j==0) dp[0][0]=1;
    //             else{
    //                 int up=0;
    //                 int left=0;
    //                 if(i>0) up= dp[i-1][j];
    //                 if(j>0) left= dp[i][j-1];
    //                 dp[i][j]=up+left;
    //             }
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // return solve(obstacleGrid,m,n,0,0);
        // vector<vector<int>>dp(m,vector<int>(n,0));
        // return solveMem(obstacleGrid,m,n,0,0,dp);
        return solveTab(obstacleGrid,m,n);
    }
};