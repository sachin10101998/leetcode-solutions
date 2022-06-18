class Solution {
public:
    vector<string> split(string s){
        vector<string> temp;
        string temp2="";
        for(int i=0;i<s.length();i++) {
            if(s[i]!= ' ') {
                temp2=temp2+s[i];
            } else {
                if(temp2!=" ") {
                    temp.push_back(temp2);
                }
                
                temp2 = "";
            }
        }
        if(temp2!=""){
            temp.push_back(temp2);
        }
  
        return temp;
    }
    string reverseWords(string s) {
        vector<string> temp = split(s);
        reverse(temp.begin(), temp.end());
        string res="";
        for(auto x: temp){
            if(x!=""){
                res+=x;
                res+=" ";
            }
     
            
        }
        int start=0;
        int end = res.length()-1;
        for(int i=0;i<res.length();i++){
            if(res[i]!=' '){
                start=i;
                break;
            } else {
                continue;
            }
        }
        for(int i=res.length()-1;i>=0;i--){
            if(res[i]!= ' '){
                end=i;
                break;
            } else {
                continue;
            }
        }
        return res.substr(start, end-start+1);
        
    }
};