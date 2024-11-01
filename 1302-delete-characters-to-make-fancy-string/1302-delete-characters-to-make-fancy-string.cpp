class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int count=1;
        for(int i=0;i<s.size()-1;i++){
            if(count<3){
              ans.push_back(s[i]);
            }
            if(s[i]==s[i+1]){
                count++;
            }else{
                count=1;
            }
            
        }
        if(count<3){
            ans.push_back(s[s.size()-1]);
        }
        return ans;
    }
};