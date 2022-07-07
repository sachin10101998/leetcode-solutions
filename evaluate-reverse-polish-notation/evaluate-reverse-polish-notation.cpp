class Solution {
public:
    bool checkSign(string s){
        if(s=="+"||s=="-"||s=="/"||s=="*"){
            return true;
        }
         else {
             return false;
         }
    }
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        stack<int>s;
        for(int i=0;i<size;i++){
            if(!checkSign(tokens[i])){
                s.push(stoi(tokens[i]));
            } else {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                if(tokens[i]=="+"){
                    s.push(first+second);
                } else if(tokens[i]=="-"){
                    s.push(second-first);
                } else if(tokens[i]=="*"){
                    s.push(first*second);
                } else {
                    s.push(int(second/first));
                }
            }
        }
        return s.top();
    }
};