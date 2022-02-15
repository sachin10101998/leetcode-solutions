class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m1;
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
        }
        vector<pair<int,int>> v1;
        for (auto x: m1){
            v1.push_back({x.second,x.first});
        }
        sort(v1.begin(), v1.end(), greater<pair<int,int>>());
        vector<int> v2;
        for(int i=0;i<k;i++){
            v2.push_back(v1[i].second);
        }
        return v2;
    }
};