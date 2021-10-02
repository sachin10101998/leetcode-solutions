class Solution {
public:
    bool isValid(vector<string>& curr, int row, int col, int n) {
        for (int i = 0; i < row; i++) 
            if (curr[i][col] == 'Q') 
                return false;
        for (int i = row-1, j = col-1; i >= 0 and j >= 0; i--, j--) 
            if (curr[i][j] == 'Q')
                return false;
        for (int i = row-1, j = col+1; i >= 0 and j < n; i--, j++)
            if (curr[i][j] == 'Q')
                return false;
        return true;
    }
    
    void fun(vector<vector<string>>& res, vector<string>& curr, int row, int n) {
        if (row == n) {
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (isValid(curr, row, i, n)) {
                curr[row][i] = 'Q';
                fun(res, curr, row+1, n);
                curr[row][i] = '.';     // Backtracking
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr(n, string (n, '.'));
        fun(res, curr, 0, n);
        return res;
    }
};