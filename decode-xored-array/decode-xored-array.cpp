class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>answer(encoded.size()+1);
        answer[0]=first;
        for(int i=1;i<=encoded.size();i++){
            answer[i]=encoded[i-1]^answer[i-1];
        }
        return answer;
    }
};