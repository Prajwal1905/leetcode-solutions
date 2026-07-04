class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int j=0;
        while(j<s.length()){
            while(j<s.length() && s[j]==' ') j++;
            if(i>0 && j<s.length()){
                s[i++]=' ';
            }
            while(j<s.length() && s[j]!=' '){
                s[i]=s[j];
                i++;
                j++;
            }
        }
        s.resize(i);
        reverse(s.begin(),s.end());
        int start=0;
        for(int end=0;end<=s.length();end++){
            if(end==s.length() || s[end]==' '){
                reverse(s.begin()+start,s.begin()+end);
                start=end+1;
            }
        }
        return s;
    }
};