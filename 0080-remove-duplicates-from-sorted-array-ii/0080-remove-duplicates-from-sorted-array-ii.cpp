class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1;
        int cnt=1;
        for(int i=1;i<nums.size();i++){
           if(nums[i]==nums[i-1] && cnt<2){
            cnt++;
            nums[j]=nums[i];
            j++;
           }
           else if(nums[i]!=nums[i-1]){
            nums[j]=nums[i];
            j++;
            cnt=1;
           }
           else{
            continue;
           }
        }
        return j;

    }
};