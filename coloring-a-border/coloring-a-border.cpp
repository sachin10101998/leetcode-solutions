class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int x[4]={0,1,0,-1};
        int y[4]={1,0,-1,0};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({r0,c0});
        int col=grid[r0][c0];
        vector<vector<int>> vis(n,vector<int>(m,-1));
        vector<vector<int>> ans(n,vector<int>(m));
        ans=grid;
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            //cout<<p.first<<" "<<p.second<<endl;
            vis[p.first][p.second]=1;
            bool tem=false;
            for(int i=0;i<4;i++)
            {
                int x_=x[i]+p.first;
                int y_=y[i]+p.second;
                //cout<<x_<<" "<<y_<<" "<<endl;
                if(x_>=0&&y_>=0&&x_<n&&y_<m&&grid[x_][y_]==col)
                {
                    if(vis[x_][y_]==-1)
                     q.push({x_,y_});  
                 }
                else
                 tem=true;
            }
            if(tem)
                ans[p.first][p.second]=color;
        }
        return ans;
    }
};