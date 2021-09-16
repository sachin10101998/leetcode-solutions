class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int H = M.size(), W = H?M[0].size():0, res = 0;
        vector<vector<vector<int>>> dp(H, vector<vector<int>>(W, vector<int>(4, 0)));
        for(int i=0;i<H;i++) 
            for(int j=0;j<W;j++)
                if(M[i][j]==1) {
                    res=max(res,  dp[i][j][0]= 1 + (j?dp[i][j-1][0]:0)  ); // horizontal
                    res=max(res,  dp[i][j][1]= 1 + (i?dp[i-1][j][1]:0)  ); // vertical
                    res=max(res,  dp[i][j][2]= 1 + (i&&j?dp[i-1][j-1][2]:0)  ); // diagonal
                    res=max(res,  dp[i][j][3]= 1 + (i&&j<W-1?dp[i-1][j+1][3]:0)  ); // anti-diagonal
                }
        return res;
    }
};