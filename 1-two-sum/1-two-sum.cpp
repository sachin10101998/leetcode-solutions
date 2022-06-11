class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m1;
        int sum=0;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
   
            if(m1.find(target-nums[i])!=m1.end()){
                res.push_back(i);
                res.push_back(m1[target-nums[i]]);
                break;
            } else{
                m1[nums[i]]=i;
            }
        }
        return res;
    }
};