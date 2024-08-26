class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        int minround = 0;
        unordered_map<int , int> mpp;
        for(int i = 0 ; i<n ; i++){
            mpp[tasks[i]]++;
        }
        for(auto it:mpp){
            if(it.second < 2){
                return -1;
            }
            if(it.second % 3 == 0){
                minround = minround + it.second/3;
            }
            if(it.second % 3 == 1){
                minround = minround+2;
                it.second = it.second - 4;
                minround = minround + it.second/3;
            }
            if(it.second % 3 == 2){
                minround = minround+1;
                it.second = it.second - 2;
                minround = minround + it.second/3;
            }
        }
        return minround;
    }
};