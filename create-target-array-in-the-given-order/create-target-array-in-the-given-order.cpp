#include <bits/stdc++.h>
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> answer;
        for(int i=0;i<nums.size();i++){
            int ind = index[i];
            int val = nums[i];
            answer.insert(answer.begin()+ind,val);
        }
        return answer;
    }
};