class Solution {
public:
    int solve(vector<int> nums, int index){
        int pivot = nums[index];
        if(index==nums.size()-1){
            return -1;
        }
        for(int i=index+1;i<nums.size();i++){
            if(nums[i]>pivot){
                return nums[i];
            }
        }
        return -1;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m1;
        for(int i=0;i<nums2.size();i++){
            m1[nums2[i]]=i;
        }
        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            result.push_back(solve(nums2, m1[nums1[i]]));
        }
        return result;
        
    }
};