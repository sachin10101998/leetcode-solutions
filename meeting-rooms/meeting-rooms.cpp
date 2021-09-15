class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        bool answer = true;
        if(intervals.size()<=1){
            return answer;
        }
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(int j=1;j<intervals.size();j++){
            if(intervals[j][0]<output.back()[1]){
                return false;
            } else{
                output.push_back(intervals[j]);
            }
        }
        return true;
    }
};