class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int write=0;
        while(i<chars.size()){
            char current=chars[i];
            int count=0;
            while(i<chars.size() && chars[i]==current){
                count++;
                i++;
            }
            chars[write]=current;
            write++;
            if(count>1){
                string num=to_string(count);
                for(char digit:num){
                    chars[write]=digit;
                    write++;
                }
            }
        }
        return write;
    }
};