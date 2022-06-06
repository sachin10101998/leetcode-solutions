class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> first = {1};
        vector<int> second = {1,1};
        result.push_back(first);
        if(numRows==1){
            return result;
        }
        result.push_back(second);
        if(numRows==2){
            return result;
        }
        numRows-=2;
        for(int i=0;i<numRows;i++){
            result.push_back(nextRow(result.back()));
        }
        return result;
    }
    
    vector<int> nextRow(vector<int> givenRow) {
        int n = givenRow.size();
        vector<int> temp;
        temp.push_back(givenRow[0]);
        for(int i=0;i<givenRow.size()-1;i++){
            temp.push_back(givenRow[i]+givenRow[i+1]);
        }
        temp.push_back(givenRow[givenRow.size()-1]);
        return temp;
    }
};