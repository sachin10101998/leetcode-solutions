class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res;
        stack<pair<int,int>>s;
        map<int,int> ng;
        for(int i=0;i<temp.size();i++){
            if(s.empty()){
                s.push(make_pair(i,temp[i]));
            } else {
                if(s.top().second>temp[i]){
                    s.push(make_pair(i,temp[i]));
                } else {
                    while(!s.empty()&&s.top().second<temp[i]){
                        int topp = s.top().second;
                        int toppindex = s.top().first;
                        s.pop();
                        ng[toppindex]=i;
                    }
                    s.push(make_pair(i,temp[i]));
                }
            }
        }
        for(int i=0;i<temp.size();i++){
            if(ng.find(i)!=ng.end()){
                res.push_back(ng[i]);
            }
            else {
                res.push_back(-1);
            }
        }
  
        vector<int> res2;
        for(int i=0;i<temp.size();i++){
            if(res[i]!=-1){
                res2.push_back(res[i]-i);
            } else {
                res2.push_back(0);
            }
            
            
        }
        for(auto x: res2){
            cout<<x<<endl;
        }
        return res2;
    }
};