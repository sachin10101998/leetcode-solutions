class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = INT_MIN;
        for(int i=0;i<accounts.size();i++){
            int anss=0;
            for(int j=0;j<accounts[0].size();j++){
                anss+=accounts[i][j];
            }
            ans = max(ans,anss);
        }
        return ans;
    }
};