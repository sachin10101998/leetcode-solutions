class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal(rowIndex+1, vector<int>(rowIndex+1));
        vector<int> temp = {1};
        pascal[0]=temp;
        for(int i=1;i<=rowIndex;i++) {
            for(int j=0;j<=rowIndex;j++) {
                if(j==0) {
                    pascal[i][j]=1;
                } else{
                    pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
                }
            }
        }
        return pascal[rowIndex];
    }
};