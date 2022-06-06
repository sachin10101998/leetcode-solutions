class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int total = mat[0].size()*mat.size();
        vector<int> result;
        int i=0;
        int j=0;
        int d = 0;
        int rightLimit = mat[0].size()-1;
        int downLimit = mat.size()-1;
        int leftLimit = 0;
        int upLimit = 1;
        while(true){
            if(result.size()==total) {
                break;
            }
            result.push_back(mat[i][j]);
            if(d==0 && j==rightLimit) {
                d = (d+1)%4;
                rightLimit--;
            }
            if(d==1 && i == downLimit) {
                d = (d+1)%4;
                downLimit--;
            }
            if(d ==2 && j ==leftLimit) {
                d = (d+1)%4;
                leftLimit++;
            }
            if(d == 3 && i ==upLimit) {
                upLimit++;
                d = (d+1)%4;
            }
            
            if(d==0) {
                j++;
            }
            else if(d==1){
                i++;
            }
            else if(d==2){
                j--;
            }
            else if(d==3){
                i--;
            }
        }
        return result;
        
    }
};