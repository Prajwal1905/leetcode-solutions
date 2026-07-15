class Solution {
public:
    string decodeString(string s) {
        stack<int>numStack;
        stack<string>strStack;
        int num=0;
        string curr="";
        for(char ch:s){
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }else if(ch=='['){
                numStack.push(num);
                strStack.push(curr);
                curr="";
                num=0;
            }else if(ch==']'){
                int repeat=numStack.top();
                numStack.pop();
                string prev=strStack.top();
                strStack.pop();
                while(repeat--){
                    prev+=curr;
                }
                curr=prev;
            }else{
                curr+=ch;
            }
        }
        return curr;
    }
};