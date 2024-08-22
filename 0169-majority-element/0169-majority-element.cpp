

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         int ans = 0;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             if (mp.find(nums[i]) == mp.end()) {
//                 pair<int, int> p = make_pair(nums[i], 1);
//                 mp.insert(p);
//             } else {
//                 mp[nums[i]]++;
//             }
//         }

//         unordered_map<int, int>::iterator it = mp.begin();
//         while (it != mp.end()) {
//             if (it->second > n / 2) {
//                 ans = it->first;
//                 // break; // Break out of the loop once a majority element is found
//             }
//             it++;
//         }
     

//         return ans;
//     }
// };

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int> a;
//         int n=nums.size();
//         for(int i:nums)
//             a[i]++;
//         int ans=0;
//         for(auto x:a)
//         {
//             if(x.second>n/2)
//                 ans=x.first;
//         }
//         return ans;
//     }
// };


// Moore's Voting Algo
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int n=nums.size();
      int count=0;
      int ele=nums[0];
      for(int i=0;i<n;i++){
        if(count==0){
            ele=nums[i];
            count++;
        }
        else if(nums[i]==ele){
            count++;
        }
        else{
            count--;
        }
        
      }
      int cnt=0;
      for(int i=0;i<n;i++){
        if(nums[i]==ele) cnt++;
      }
      if(cnt>n/2){
        return ele;
      }
      return 0;
    }
};