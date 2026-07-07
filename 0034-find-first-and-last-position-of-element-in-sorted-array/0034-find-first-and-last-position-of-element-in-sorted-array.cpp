class Solution {
public:
    int findFirst(vector<int>&nums,int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int m=low+(high-low)/2;
            if(nums[m]==target){
                ans=m;
                high=m-1;
            }else if(nums[m]<target){
                low=m+1;
            }else{
                high=m-1;
            }
        }
        return ans;
    }
    int findLast(vector<int>&nums,int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int m=low+(high-low)/2;
            if(nums[m]==target){
                ans=m;
                low=m+1;
            }else if(nums[m]<target){
                low=m+1;
            }else{
                high=m-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=findFirst(nums,target);
        int last=findLast(nums,target);
        return {first,last};
        
    }
};