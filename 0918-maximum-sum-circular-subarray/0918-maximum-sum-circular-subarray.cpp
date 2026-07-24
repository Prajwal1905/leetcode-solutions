class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        int currMin=0;
        int minSum=INT_MAX;
        int currMax=0;
        int maxSum=INT_MIN;
        for(int num:nums){
            totalSum+=num;
            currMin=min(num,currMin+num);
            minSum=min(minSum,currMin);
            currMax=max(num,currMax+num);
            maxSum=max(maxSum,currMax);
        }
        if(maxSum<0){
            return maxSum;
        }
        return max(maxSum,totalSum-minSum);
    }
};