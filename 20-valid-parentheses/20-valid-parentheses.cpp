class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                cout<<"Pushing"<<s[i]<<endl;
            } else if(s[i]==')'){
                if(st.size()==0) {
                    return false;
                }
                if(st.top()=='(') {
                    cout<<"Popping"<<st.top()<<endl;
                    st.pop();
                    continue;
                } else {
                    return false;
                }
            } else if(s[i]=='}') {
                if(st.size()==0) {
                    return false;
                }
                if(st.top()=='{'){
                    st.pop();
                    continue;
                } else {
                    return false;
                }
            } else if(s[i]==']') {
                if(st.size()==0) {
                    return false;
                }
                if(st.top()=='['){
                    st.pop();
                    continue;
                } else {
                    return false;
                }
            }  
        }
        if(st.size()==0){
            return true;
        } else {
            cout<<"Coming";
            return false;
        }
    }
};