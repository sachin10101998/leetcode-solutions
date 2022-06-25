class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> q;
        int r = rooms.size();
        int rd[4] = {0,0,1,-1};
        int rc[4] = {1,-1,0,0};
        if(r==0){
            return;
        }
        int c = rooms[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(rooms[i][j]==0){
                    q.push(make_pair(i,j));
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> pp = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int rdd = pp.first + rd[j];
                    int rcd = pp.second + rc[j];
                    if(rdd<0||rdd>=r ||rcd < 0||rcd >=c ||rooms[rdd][rcd]<=rooms[pp.first][pp.second]){
                        continue;
                    } 
                    if(rooms[rdd][rcd]>rooms[pp.first][pp.second]+1){
                        rooms[rdd][rcd]=rooms[pp.first][pp.second]+1;
                    }
                    q.push(make_pair(rdd,rcd));
                }
            }
        }
        return;
    }
};