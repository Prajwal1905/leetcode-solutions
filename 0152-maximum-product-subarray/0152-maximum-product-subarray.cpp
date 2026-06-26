class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxProd=nums[0];
        int minProd=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int temp=maxProd;
            maxProd=max(nums[i],max(nums[i]*maxProd,nums[i]*minProd));
            minProd=min(nums[i],min(nums[i]*temp,nums[i]*minProd));
            ans=max(ans,maxProd);

        }
        return ans;
    }
};