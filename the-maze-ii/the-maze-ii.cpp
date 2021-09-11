// BFS Solution
class Solution {
    vector<vector<int>> dirs_ = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        const int m = maze.size(), n = maze[0].size();
        if (m == 0 || n == 0) return -1;
        
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int,int>> q;
        q.push({start[0], start[1]});
        dist[start[0]][start[1]] = 0; // Initialize first distance
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            for (const auto& d : dirs_) {
                int x = cur.first, y = cur.second;
                int cur_dist = dist[cur.first][cur.second];
                while (x+d[0] >= 0 && x+d[0] < m && y+d[1] >= 0 && y+d[1] < n && !maze[x+d[0]][y+d[1]]) {
                    x += d[0]; y += d[1];
                    ++cur_dist;
                }
                // first time visit or we have shorter distance solution
                if (dist[x][y] == -1 || cur_dist < dist[x][y]) {
                    dist[x][y] = cur_dist;
                    q.push({x, y});
                }
            }
        }
        return dist[dest[0]][dest[1]];        
    }
};