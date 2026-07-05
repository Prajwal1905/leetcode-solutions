class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        vector<int>freq(128,0);
        for(char ch:t)
           freq[ch]++;
        int left=0;
        int minLen=INT_MAX;
        int start=0;
        int required=t.length();
        for(int right=0;right<s.length();right++){
            if(freq[s[right]]>0)
               required--;
            freq[s[right]]--;
            while(required==0){
                int windowLen=right-left+1;
                if(windowLen<minLen){
                    minLen=windowLen;
                    start=left;
                }
                freq[s[left]]++;
                if(freq[s[left]]>0)
                    required++;
                left++;
            }
        }
        if(minLen==INT_MAX) return "";
        return s.substr(start,minLen);

        
    }
};