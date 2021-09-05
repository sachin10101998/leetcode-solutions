//Approach-1 (Using O(n) space)
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> left(n);
        vector<int> right(n);
        
        //Calculate cumulative sum from left to right
        left[0] = nums[0];
        for(int i = 1; i< n; i++) {
            left[i] = nums[i] + left[i-1];
        }
        
        //Calculate cumulative sum from right to left
        right[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            right[i] = nums[i] + right[i+1];
        }
        
        //if at any i, left cumulative sum == right cumulative sum, that's my answer
        for(int i = 0; i<n; i++) {
            if(left[i] == right[i])
                return i;
        }
        
        return -1;
    }
};