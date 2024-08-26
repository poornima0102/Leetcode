#define MOD 1000000007
class Solution {
public:
    int memo(int n, vector<int>& dp) {
        if (n == 0) return 1; // 2 ways: place a house or leave it empty
        if (n == 1) return 2; // 3 ways: 00, 01, 10

        if (dp[n] != -1) return dp[n];

        // Place a house at position `n` and consider n-2's configuration
        int take = memo(n - 2, dp) % MOD;
        // Do not place a house at position `n` and consider n-1's configuration
        int notTake = memo(n - 1, dp) % MOD;

        dp[n] = (take + notTake) % MOD;
        return dp[n];
    }

    int countHousePlacements(int n) {
        vector<int> dp(n + 1, -1); // Initialize dp with -1
        int ans = memo(n, dp);
        return (1LL * ans * ans) % MOD; // Square the result and apply modulo
    }
};
//1LL: A literal representing the number 1 as a long long integer.
//Purpose: To ensure arithmetic operations are performed using long long to prevent overflow
// and handle large values correctly.


//Why multiplication? Because for every configuration on Side A, you can pair it with any configuration on Side B.
// This is the principle of independent events in combinatorics.






// class Solution {
// public:
// long long mod = 1e9+7;
//     int countHousePlacements(int n) {
        
// vector<long long >dp(n+1,-1);

//         dp[0] = 1;  
//         dp[1]=2;

//         for(int i=2;i<=n;i++)
//          {
//             dp[i] = (dp[i-1]+dp[i-2])%mod;
//          }

//          return (dp[n]*dp[n])%mod;
//     }
// };
