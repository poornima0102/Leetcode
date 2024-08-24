class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(string s,vector<string> output,vector<vector<string>>& ans,int idx){
      if(idx>=s.size()){
        ans.push_back(output);
        return;
      }
      for(int i=idx;i<s.size();i++){
        if(isPalindrome(s,idx,i)){
            output.push_back(s.substr(idx,i-idx+1));
            solve(s,output,ans,i+1);
            output.pop_back();
        }
    
      }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(s,output,ans,0);
        return ans;
        
    }
};