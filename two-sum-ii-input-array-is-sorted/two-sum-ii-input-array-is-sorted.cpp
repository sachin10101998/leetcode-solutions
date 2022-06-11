class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j= nums.size()-1;
        vector<int>res;
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            } else if(nums[i]+nums[j]<target){
                i++;
            } else{
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
        }
        return res;
    }
};