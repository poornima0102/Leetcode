class Solution {
public:
    // void rotate(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     for(int j=1;j<=k;j++){
    //         int var=nums[n-1];
    //          for(int i=n-1;i>0;i--){
    //              nums[i]=nums[i-1];
    //     }
    //     nums[0]=var;
    //     }
        
    // }

    
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k is greater than n
    reverse(nums.begin(), nums.end()); // Reverse the entire array
    reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
    reverse(nums.begin() + k, nums.end()); // Reverse the remaining elements
}
};


