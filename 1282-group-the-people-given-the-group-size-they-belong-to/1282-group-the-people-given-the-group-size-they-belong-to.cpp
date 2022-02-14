class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        vector<vector<int>> gz (groupSizes.size()+1);
        for(int i=0;i<groupSizes.size();i++){
            gz[groupSizes[i]].push_back(i);
            if(gz[groupSizes[i]].size()==groupSizes[i]){
                res.push_back({});
                swap(res.back(),gz[groupSizes[i]]);
            }
        }
        return res;
    }
};