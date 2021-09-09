class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        memset(dp, 1, sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int max_ans = INT_MIN;
        for(int i=0;i<n;i++){
            max_ans = max(max_ans,dp[i]);
        }
        return max_ans;
    }
};