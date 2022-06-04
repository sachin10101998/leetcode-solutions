class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        if(nums.size()==1) {
            return 0;
        }
        
        for(auto x: nums) {
            sum+=x;
        }
        vector<int> leftSum;
        vector<int> rightSum;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            temp+=nums[i];
            leftSum.push_back(temp);
        }
        temp=0;
        for(int i=nums.size()-1;i>=0;i--){
            temp+=nums[i];
            rightSum.push_back(temp);
        }
        reverse(rightSum.begin(), rightSum.end());
        for(int i=0;i<nums.size();i++){
            if(i==0){
                if(rightSum[1]==0){
                    return 0;
                }
            } else if(i==nums.size()-1) {
                if(leftSum[nums.size()-2]==0){
                    return nums.size()-1;
                }
            } else {
                if(leftSum[i-1]==rightSum[i+1]){
                    return i;
                }
            }
        }
        return -1;
    }
};