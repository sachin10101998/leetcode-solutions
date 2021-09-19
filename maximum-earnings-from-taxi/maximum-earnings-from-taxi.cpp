using ll= long long;
class Solution {
public:
    vector<vector<pair<int,int>>> edges;
    ll rec(int level,vector<ll>&dp)
    {
        if(level==0)
            return 0;
        
        if(dp[level]!=-1){
            return dp[level];
        }
        
        ll ans = rec(level-1,dp); //not picking the passenger at this level.
        
        //if picking the passenger check all the best possiblity.
        for(auto& [src,cost] : edges[level])
        {
            ans = max(ans,rec(src,dp) + cost);
        }
        
        return dp[level]=ans;
        
    }
    
    ll maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int R = rides.size();
        edges.clear();
        edges.resize(n+5);
        vector<ll>dp(n+5,-1);
        
        for(int i=0;i<R;i++)
        {
            int start = rides[i][0], end=rides[i][1];
            int tip=rides[i][2];
            int cost=end-start+tip;
            edges[end].push_back({start,cost});
        }
        
        return rec(n,dp);
    }
};