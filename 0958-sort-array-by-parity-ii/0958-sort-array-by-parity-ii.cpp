class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
    
        // Initialize two pointers: even index and odd index
        int e = 0, o = 1;

        // Loop until either pointer exceeds the array size
        while(e < nums.size() && o < nums.size()) {

            // Move even pointer forward if the number is already even
            while(e < nums.size() && nums[e] % 2 == 0) {
                e += 2;
            }

            // Move odd pointer forward if the number is already odd
            while(o < nums.size() && nums[o] % 2 == 1) {
                o += 2;
            }

            // Swap if both pointers point to incorrect placements
            if(e < nums.size() && o < nums.size()) {
                swap(nums[o], nums[e]);
            }
        }

        // Return the corrected array
        return nums;
    }
};
