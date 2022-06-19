class Solution {
public:
    vector<string> split(string s){
        vector<string> temp;
        string temp2 = "";
        for(int i=0;i<s.length();i++){
            if(s[i]!= ' ') {
                temp2=temp2+s[i];
                
            } else {
                temp.push_back(temp2);
                temp2.clear();
            }
        }
        if(temp2!=""){
            temp.push_back(temp2);
        }
        return temp;
    }
    string reverseWords(string s) {
        vector<string> temp = split(s);
        cout<< temp.size();
        for(int i=0;i<temp.size();i++){
            string p = temp[i];
            reverse(p.begin(), p.end());
            temp[i]=p;
        }
        for(auto x : temp) {
            cout<<x;
        }
        string res="";
        for(auto x: temp){
            res+=x;
            res=res+" ";
        }
        cout<<res;
        res=res.substr(0,res.size()-1);
        return res;
    }
};