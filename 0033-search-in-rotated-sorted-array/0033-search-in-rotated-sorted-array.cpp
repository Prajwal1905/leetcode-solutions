class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int m=low+(high-low)/2;
            if(nums[m]==target){
                return m;
            }
            if(nums[low]<=nums[m]){
                if(nums[low]<=target && target<nums[m]){
                    high=m-1;
                }else{
                    low=m+1;
                }
            }else{
                if(nums[m]<target && target<=nums[high]){
                    low=m+1;
                }else{
                    high=m-1;
                }
            }
        }
        return -1;

    }
};