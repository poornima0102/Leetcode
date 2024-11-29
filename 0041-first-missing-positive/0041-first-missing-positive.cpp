class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());  // Correct unordered_set syntax
        int k = 1;

        // Iterate through all integers starting from 1
        while (st.find(k) != st.end()) {  // If k is in the set, increment k
            k++;
        }

        return k;  // Return the first missing positive integer
    }
};
