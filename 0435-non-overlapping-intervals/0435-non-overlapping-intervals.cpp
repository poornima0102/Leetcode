class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int count=0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(ans.empty() || start>=ans.back()[1]){
                ans.push_back(intervals[i]);
            }else{
                count++;
            }
        }
        return count;
    }
};