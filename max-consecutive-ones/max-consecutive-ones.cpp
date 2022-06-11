class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr_ones=0;
        int max_ones=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr_ones+=1;
                max_ones=max(max_ones,curr_ones);
            } else {
                curr_ones=0;
            }
        }
        return max_ones;
    }
};