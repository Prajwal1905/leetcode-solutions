class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxArea=0;
        int left=0;
        int right=n-1;
        while(left<right){
            int width=right-left;
            int currArea=min(height[left],height[right])*width;
            maxArea=max(maxArea,currArea);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};