class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            if(nums[i]%2==0 && nums[j]%2!=0){
                j--;
            }
            else if(nums[i]%2==0 && nums[j]%2==0){
                i++;
            }
            else if(nums[i]%2!=0 && nums[j]%2!=0){
                j--;
            }else{
                int temp=0;
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                i++;
                j--;
            }
        }
        return nums;
    }
};