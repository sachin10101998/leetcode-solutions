class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[j-1]) {
                nums[i]=nums[j];
                i++;
            } else {
                continue;
            }
        }
        return i;
    }
};