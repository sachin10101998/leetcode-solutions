class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(auto x: nums){
            sum+=x;
        }
        int leftSum=0;
        for(int i=0;i<nums.size();i++){
            if(sum-leftSum-nums[i]==leftSum){
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
        
    }
};