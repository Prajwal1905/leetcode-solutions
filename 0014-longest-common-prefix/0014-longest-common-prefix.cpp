class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string ans="";
        for(int i=0;i<strs[0].length();i++){
            char current=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].length() || strs[j][i]!=current)
                    return ans;
                
                
            }
            ans+=current;
        }
        return ans;
    }
};