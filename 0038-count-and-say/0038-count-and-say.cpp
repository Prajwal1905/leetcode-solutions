class Solution {
public:
    string countAndSay(int n) {
        string curr="1";
        for(int step=2;step<=n;step++){
            string next="";
            int i=0;
            while(i<curr.length()){
                char ch=curr[i];
                int count=0;
                while(i<curr.length() && curr[i]==ch){
                    count++;
                    i++;
                }
                next+=to_string(count);
                next+=ch;
            }
            curr=next;
        }
        return curr;
    }
};