class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char ch:s){
            freq[ch]++;
        }
        priority_queue<pair<int,int>>maxHeap;
        for(auto it:freq){
            maxHeap.push({it.second,it.first});
        }
        string ans="";
        while(!maxHeap.empty()){
            int count=maxHeap.top().first;
            char ch=maxHeap.top().second;
            maxHeap.pop();
            ans+=string(count,ch);
        }
        return ans;
    }
};