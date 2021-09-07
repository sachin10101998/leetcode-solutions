class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>result(nums.size());
        for(int i=0;i<nums.size();i++){
            int count=0;
            for(int j=0;j<nums.size();j++){
                if(i!=j&&nums[j]<nums[i]){
                    count++;
                }
            }
            result[i]=count;
        }
        return result;
        
    }
};