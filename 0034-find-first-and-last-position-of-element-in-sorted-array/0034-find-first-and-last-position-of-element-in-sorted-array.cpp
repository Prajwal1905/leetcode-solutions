class Solution {
public:
    int firstOcc(vector<int>&nums,int target){
        int n=nums.size();
        int left=0;
        int right=n-1;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                ans=mid;
                right=right-1;
            }else if(nums[mid]<target){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
    int lastOcc(vector<int>&nums,int target){
        int n=nums.size();
        int left=0;
        int right=n-1;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                ans=mid;
                left=left+1;
            }else if(nums[mid]<target){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOcc(nums,target),lastOcc(nums,target)};
        
    }
};