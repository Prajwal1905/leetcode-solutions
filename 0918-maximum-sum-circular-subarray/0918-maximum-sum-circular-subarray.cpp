class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        int currMax=0;
        int maxSum=INT_MIN;
        int currMin=0;
        int minSum=INT_MAX;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
            currMax=max(nums[i],currMax+nums[i]);
            maxSum=max(maxSum,currMax);
            currMin=min(nums[i],currMin+nums[i]);
            minSum=min(minSum,currMin);
        }
        if(maxSum<0){
            return maxSum;
        return 0;

        }
        return max(maxSum,totalSum-minSum);

    }
};