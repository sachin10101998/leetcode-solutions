class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char>answer(s.length());
        int n = s.length();
        for(int i=0;i<n;i++){
            int temp = indices[i];
            answer[temp]=s[i];
        }
        string answerr="";
        for(int i=0;i<n;i++){
            answerr+=answer[i];
        }
        return answerr;
    }
};