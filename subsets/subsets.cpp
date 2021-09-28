class Solution {
public:
    vector<vector<int>> ans;
    void backTrack(int curr_node, vector<int>&path, vector<int>& nums){
        ans.push_back(path);
        for(int i=curr_node;i<nums.size();i++){
            path.push_back(nums[i]);
            backTrack(i+1,path,nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0){
            return ans;
        }
        vector<int> temp_ans;
        backTrack(0, temp_ans, nums);
        return ans;
        
        
    }
};