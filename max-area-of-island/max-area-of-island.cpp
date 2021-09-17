class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (grid[i][j] == 1) ans = max(ans, area(grid, i, j));
        return ans;
    }
private:
    int area(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size(), area = 1;
        queue<pair<int,int>> myq;
        myq.push({row, col});
        grid[row][col] = 2;
        vector<int> dir({-1,0,1,0,-1});
        while (!myq.empty()) {
            int z = myq.front().first, x = myq.front().second;
            myq.pop();
            for (int i = 0; i < 4; i++) {
                int r = z+dir[i], c = x+dir[i+1];
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                    grid[r][c] = 2;
                    area++;
                    myq.push({r,c});
                }
            }
        }
        return area;
    }
};