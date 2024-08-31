class Solution {
public:
    // int solveRec(vector<vector<int>>& triangle,int m,int i,int j){
    //     if(i==m-1 ){
    //         return triangle[i][j];
    //     }
        
    //     int sum=triangle[i][j]+min(solveRec(triangle,m,i+1,j),solveRec(triangle,m,i+1,j+1));
    //     return sum;
    // }
     int solveTab(vector<vector<int>>& triangle,int m){
        vector<vector<int>> dp(m,vector<int>(m,INT_MAX));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<m;i++){
            for(int j=0;j<=i;j++){
                if(j==0)
                dp[i][j]=triangle[i][j]+dp[i-1][j];
                else
                dp[i][j]=triangle[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
            }
        }
        int mini=INT_MAX;
        for(int k=0;k<m;k++){
            mini=min(mini,dp[m-1][k]);
        }
        return mini;
     }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        
        // return solveRec(triangle,m,0,0);
        return solveTab(triangle,m);
    }
};