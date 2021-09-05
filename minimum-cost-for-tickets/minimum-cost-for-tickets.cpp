class Solution {
public:
    int forward(vector<int>& days, vector<int>& costs) {
        unordered_set<int> dayset(days.begin(), days.end());

        vector<int> dp(366, 0);
        for(int i = 1; i < 366; ++i) {
            if (dayset.find(i) == dayset.end()) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = min({dp[i-1] + costs[0], 
                             dp[max(i-7, 0)] + costs[1],
                             dp[max(i-30, 0)] + costs[2]});
            }
        }

        return dp[365];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return forward(days, costs);
    }
};