// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         int n=intervals.size();
//         int count=0;
//         sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
//             return a[1] < b[1];
//         });
//         vector<vector<int>> ans;
//         for(int i=0;i<n;i++){
//             int start=intervals[i][0];
//             int end=intervals[i][1];
//             if(ans.empty() || start>=ans.back()[1]){
//                 ans.push_back(intervals[i]);
//             }else{
//                 count++;
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        
        // Sort intervals by their end times to minimize overlapping intervals.
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int start = intervals[i][0];
            // Check if there's an overlap with the previous interval
            if (start < end) {
                count++; // Increment count if there's an overlap
            } else {
                end = intervals[i][1]; // Update the end time for the next comparison
            }
        }
        
        return count;
    }
};
