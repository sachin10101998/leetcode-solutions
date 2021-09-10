class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] > a) {
                b = a;  // delegate previous max value to 2nd max value
                a = nums[i];  // set new max value
            } else if (nums[i] > b) {
                b = nums[i];
            }
        }
        return (a-1)*(b-1);
    }
};