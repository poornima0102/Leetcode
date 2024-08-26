class Solution {
public:
    int bottomUp(int n){
        vector<int>dp(n+1,-1);
        dp[0]=0;
        if(n==0) return dp[0];
        dp[1]=1;
        if(n==1) return dp[1];
        dp[2]=1;
        if(n==2) return dp[2];
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1];
            if(i-2>=0)
            dp[i]+=dp[i-2];
            if(i-3>=0)
            dp[i]+=dp[i-3];
        }
        return dp[n];

    }
    int tribonacci(int n) {
        return bottomUp(n);
        
    }
};