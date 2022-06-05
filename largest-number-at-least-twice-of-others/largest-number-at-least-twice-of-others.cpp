class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest_int = INT_MIN;
        int p=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>largest_int){
                largest_int = nums[i];
                p=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i!=p){
                if(2*nums[i]>largest_int){
                    return -1;
                }
            }
        }
        return p;
    }
};