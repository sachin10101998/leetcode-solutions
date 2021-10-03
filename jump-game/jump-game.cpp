class Solution {
public:
   
    bool canJump(vector<int>& nums) {
       int  n=nums.size();
        vector<int> dp(n,-1);
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            int step=nums[i];
            for(int k=1;k<=step;k++){
                if(i+k<n && dp[i+k]==1){
                    dp[i]=1;
                    break;
                }
                    
            }
        }
        if(dp[0]==1) return true;
        return false;
    }
};