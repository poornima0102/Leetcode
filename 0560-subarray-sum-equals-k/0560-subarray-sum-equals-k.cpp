class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0,sum=0;
        int n=nums.size();
        mp[0]=1;
        for(int i=0;i<n;i++){
           sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            
            mp[sum]++;
            
        }
        return ans;
        }

    
};