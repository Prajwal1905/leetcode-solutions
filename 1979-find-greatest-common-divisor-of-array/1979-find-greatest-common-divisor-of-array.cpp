class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest=nums[0];
        int largest=nums[0];
        for(int num:nums){
            smallest=min(smallest,num);
            largest=max(largest,num);
        }
        while(smallest!=0){
            int rem=largest%smallest;
            largest=smallest;
            smallest=rem;

        }
        return largest;
    }
};