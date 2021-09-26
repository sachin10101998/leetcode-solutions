class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m=2;
        int n=grid[0].size();
        
        long long lsum=0, rsum=0;
        for(int i=n-1;i>-1;--i){
            rsum += grid[0][i];
        }
        
        long long ans= LLONG_MAX;
        for(int i=0;i<n;++i){
            rsum=rsum-grid[0][i];
            ans=min(ans, max(rsum, lsum));
            lsum=lsum+grid[1][i];
        }
        return ans;
    }
};