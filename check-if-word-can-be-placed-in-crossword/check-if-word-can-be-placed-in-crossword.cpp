class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        int k=word.size();
        for(int i=0;i<m;i++){
            for(int l=0,r=k-1;r<n;l++,r++){
                if((l==0 || board[i][l-1]=='#') && (r==n-1 || board[i][r+1]=='#')){
                    int j,t=0;
                    for(j=l;j<=r;j++){
                        if(board[i][j]!=word[t++] && board[i][j]!=' ')
                            break;
                    }
                    if(j>r)
                        return true;
                    t=0;
                    for(j=r;j>=l;j--){
                        if(board[i][j]!=word[t++] && board[i][j]!=' ')
                            break;
                    }
                    if(j<l)
                        return true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int l=0,r=k-1;r<m;l++,r++){
                if((l==0 || board[l-1][i]=='#') && (r==m-1 || board[r+1][i]=='#')){
                    int j,t=0;
                    for(j=l;j<=r;j++){
                        if(board[j][i]!=word[t++] && board[j][i]!=' ')
                            break;
                    }
                    if(j>r)
                        return true;
                    t=0;
                    for(j=r;j>=l;j--){
                        if(board[j][i]!=word[t++] && board[j][i]!=' ')
                            break;
                    }
                    if(j<l)
                        return true;
                }
            }
        }
        return false;
    }
};