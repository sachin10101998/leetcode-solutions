class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>res;
        res.resize(m+n, vector<int>());
        vector<int> result;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[i+j].push_back(mat[i][j]);
            }
        }
        for(int i=0;i<res.size();i++){
            if(i%2==0){
                reverse(res[i].begin(), res[i].end());
            }
        }
        for(int i=0;i<res.size();i++){
            vector<int> temp2 = res[i];
            for(int p=0;p<temp2.size();p++){
                result.push_back(temp2[p]);
            }
        }
        
        return result;
    }
};