// class Solution {
// public:
//     bool solveTd(vector<int>& nums,int i,vector<int>& dp){
//         if(i==nums.size()-1) return true;
//         if(nums[i]==0) return false;
//         if(dp[i]!=-1)
//         return dp[i];
    
//            int jump=i+nums[i];
//            for(int j=i+1;j<=jump;j++){
//             if(j<nums.size() && solveTd(nums,j,dp))
//              return dp[i]=true;
//            }
//         return dp[i]=false;
//     }

//     bool canJump(vector<int>& nums) {
//         vector<int> dp(nums.size()+1,-1);
//         return solveTd(nums,0,dp);
//     }
// };

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         dp[n-1] = 1; //base case;
        
//         for(int idx = n-2; idx >= 0; idx--) {
//             if(nums[idx] == 0) {
//                 dp[idx] = false;
//                 continue;   
//             }
            
//             int flag = 0;
//             int reach = idx + nums[idx];
//             for(int jump=idx + 1; jump <= reach; jump++) {
//                 if(jump < nums.size() && dp[jump]) {
//                     dp[idx] = true;
//                     flag = 1;  
//                     break;
//                 }
//             }
//             if(flag == 1) 
//                 continue;
           
//             dp[idx] = false;
			
//         }
//         return dp[0]; 
//     }

//};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        //it shows at max what index can I reach.
        //initially I can only reach index 0, hence reach = 0
        int reach = 0; 
    
        for(int idx = 0; idx < nums.size(); idx++) {
            //at every index I'll check if my reach was atleast able to 
            //reach that particular index.
            
            //reach >= idx -> great, carry on. Otherwise, 
            if(reach < idx) return false;
            
            //now as you can reach this index, it's time to update your reach
            //as at every index, you're getting a new jump length.
            reach = max(reach, idx + nums[idx]);
        }
        
        //this means that you reached till the end of the array, wohooo!! 
        return true;
        
    }
};