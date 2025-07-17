class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
    int e=0,o=1;
    while(e<nums.size() && o<nums.size()){
        while(e<nums.size() && nums[e]%2==0){
            e+=2;
        }
        while(o<nums.size() && nums[o]%2!=0){
            o+=2;
        }
        if(e < nums.size() && o < nums.size()) {
            swap(nums[o], nums[e]);
        }
    }
     return nums;   
    }
};