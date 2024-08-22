class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        int j=1;
        
        for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[i-1]){
            
            nums[j]=nums[i];
            j++;
            
        }
        }
        return j;
    }
};






//     int remove_duplicate(int arr[],int n){
//         // code here
//         int j=0;
//         int i=1;
//         for(;i<n;i++){
//             if(arr[i]!=arr[i-1]){
//                 arr[j]=arr[i-1];
//                 j++;
//             }
//         }
//         arr[j]=arr[i-1]; 0r arr[j]=arr[n-1]
       
//         return j+1;
        
//     }
// };