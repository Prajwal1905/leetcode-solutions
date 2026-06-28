class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int l=0;
        int r=n-1;
        int index=n-1;
        while(l<=r){
            int leftSq=nums[l]*nums[l];
            int rightSq=nums[r]*nums[r];
            if(leftSq>rightSq){
                ans[index]=leftSq;
                l++;
            }else{
                ans[index]=rightSq;
                r--;
            }
            index--;
        }
        return ans;
        
    }
};