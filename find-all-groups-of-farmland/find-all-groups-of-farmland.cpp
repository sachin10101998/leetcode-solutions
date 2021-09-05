class Solution {
public:
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    void bfs(vector<vector<int>>& land, int sr, int sc, vector<vector<int>>& ans) {
        int er = -1, ec = -1;
        land[sr][sc] = 0;
        
        queue<pair<int,int>> q;
        q.push({sr, sc});
        
        while(q.size()) {
            auto curr = q.front(); 
            q.pop();
            
            er = curr.first;
            ec = curr.second;
            
            for(auto& dir: dirs) {
                int nr = er + dir[0], nc = ec + dir[1];
                
                if(nr>=0 && nc>=0 && nr<land.size() && nc<land[0].size() && land[nr][nc]) {
                    land[nr][nc] = 0;
                    q.push({ nr, nc });
                }
            }
        }
        
        ans.push_back({sr, sc, er, ec});
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>> land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(land[i][j] == 1) {
                    bfs(land, i, j, ans);
                }
            }
        }
        
        return ans;
    }
};