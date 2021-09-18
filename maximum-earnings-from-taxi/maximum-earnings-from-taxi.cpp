class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& A) {
        sort(A.begin(), A.end());
        vector<long long> dp(n+1);
        int j = 0;
        for(int i = 1; i <= n; ++i) {
            dp[i] = max(dp[i], dp[i - 1]);
            while (j < A.size() && A[j][0] == i)
                dp[A[j++][1]] = max(dp[A[j][1]], dp[i] + A[j][1] - A[j][0] + A[j][2]);
        }
        return dp[n];
    }
};