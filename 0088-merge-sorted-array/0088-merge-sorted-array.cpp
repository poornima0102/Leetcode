// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> merged(m + n); // Create a temporary array to hold the merged results
//         int i = 0, j = 0, k = 0;
        
//         // Merge the elements from nums1 and nums2
//         while (i < m && j < n) {
//             if (nums1[i] <= nums2[j]) {
//                 merged[k++] = nums1[i++];
//             } else {
//                 merged[k++] = nums2[j++];
//             }
//         }
        
//         // Copy any remaining elements from nums1
//         while (i < m) {
//             merged[k++] = nums1[i++];
//         }
        
//         // Copy any remaining elements from nums2
//         while (j < n) {
//             merged[k++] = nums2[j++];
//         }
        
//         // Copy the merged elements back to nums1
//         for (int l = 0; l < m + n; ++l) {
//             nums1[l] = merged[l];
//         }
//     }
// };




class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Pointer for the end of the initial part of nums1
        int j = n - 1; // Pointer for the end of nums2
        int k = m + n - 1; // Pointer for the end of nums1
        
        // Merge nums1 and nums2 from the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        // If there are remaining elements in nums2, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
        
        // No need to copy remaining elements from nums1 as they are already in place
    }
};
