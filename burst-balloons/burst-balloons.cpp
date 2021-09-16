class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // add 1 before and after nums
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        // cache the results of dp
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), 0));
        // we can not burst the first one and the last one
        // since they are both fake balloons added by ourselves
        return dp(memo, nums, 1, nums.size() - 2);
    }
	
    int dp(vector<vector<int>>& memo, vector<int>& nums, int left, int right) {
        // return maximum if we burst all nums[left]...nums[right], inclusive
        if (right - left < 0) {
            return 0;
        }

        // we've already seen this, return from cache
        if (memo[left][right] > 0) {
            return memo[left][right];
        }

        // find the last burst one in nums[left]...nums[right]
        int result = 0;
        for (int i = left; i <= right; i++) {
            // nums[i] is the last burst one
            int gain = nums[left - 1] * nums[i] * nums[right + 1];
            // nums[i] is fixed, recursively call left side and right side
            int remaining = dp(memo, nums, left, i - 1) + dp(memo, nums, i + 1, right);
            result = max(result, remaining + gain);
        }
        // add to the cache
        memo[left][right] = result;
        return result;
    }
};