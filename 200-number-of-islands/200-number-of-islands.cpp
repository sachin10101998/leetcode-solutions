class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int,int>>q1;
        int rd[4] = {0,0,1,-1};
        int rc[4] = {1,-1,0,0};
        q1.push(make_pair(i,j));
        while(!q1.empty()){
            int size = q1.size();
            for(int j=0;j<size;j++){
                int r = q1.front().first;
                int c = q1.front().second;
                q1.pop();
                for(int j=0;j<4;j++){
                    int rr = r+rd[j];
                    int cc = c+rc[j];
                    if(rr<0 || rr>=grid.size() ||cc<0 ||cc>=grid[0].size()){
                        continue;
                    }
                    if(grid[rr][cc]=='1'){
                        grid[rr][cc]='2';
                        q1.push(make_pair(rr,cc));
                    }
                    
                }
                
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        if(r==0) {
            return 0;
        }
        
        int res=0;
        int c = grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='0'){
                    continue;
                } else if(grid[i][j]=='1'){
                    res+=1;
                    bfs(grid,i,j);
                }
            }
        }
        return res;
    }
};