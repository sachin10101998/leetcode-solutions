class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res;
        k%=nums.size();
        
        reverse(nums.begin(), nums.end());
        for(int i=0;i<k;i++){
            res.push_back(nums[i]);
        }
        reverse(res.begin(), res.end());
        reverse(nums.begin(), nums.end());
        int p = nums.size()-k;
        for(int i=0;i<p;i++){
            res.push_back(nums[i]);
        }
        nums=res;
    }
};