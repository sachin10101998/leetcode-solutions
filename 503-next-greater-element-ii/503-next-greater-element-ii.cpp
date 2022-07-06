class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& num) {
        int size = num.size();
        vector<int> nums;
      
        for(auto x: num){
            nums.push_back(x);
        }
        for(auto x: num){
            nums.push_back(x);
        }
        map<int,int>ng;
        stack<pair<int,int>> s;
        for(int i=0;i<2*size;i++){
            if(s.empty()){
                s.push(make_pair(i,nums[i]));
            } else {
                if(s.top().second>nums[i]){
                    s.push(make_pair(i,nums[i]));
                } else {
                    while(!s.empty()&&s.top().second<nums[i]){
                        int topp = s.top().second;
                        int toppindex = s.top().first;
                        ng[toppindex]=nums[i];
                        s.pop(); 
                    }
                    s.push(make_pair(i,nums[i]));
                }
            }
        }
        vector<int> res;
        for(int i=0;i<size;i++){
            if(ng.find(i)!=ng.end()){
                res.push_back(ng[i]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
        
    }
};