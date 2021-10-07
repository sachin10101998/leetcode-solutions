class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string temp;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                v.push_back(temp);
                temp="";
            } else{
                temp+=s[i];
            }
        }
        v.push_back(temp);
        cout<<v.size()<<endl;
        for(auto x: v){
            for(auto y:x){
                cout<<y;
            }
            cout<<endl;
        }
        int i =0;
        int j=0;
        if(pattern.length()!=v.size()){
            return false;
        }
        unordered_set<string>ss;
        unordered_map<int,string>m1;
        for(int i=0,j=0;i<pattern.length();i++,j++){
            if(m1.find(pattern[i]-'a')==m1.end()&&ss.find(v[j])==ss.end()){
                m1[pattern[i]-'a']=v[j];
                ss.insert(v[j]);
            } else if(m1.find(pattern[i]-'a')==m1.end()&&ss.find(v[j])!=ss.end()){
                return false;
            }
            else{
                if(m1[pattern[i]-'a']!=v[j]){
                    return false;
                }
            }
        }
        return true;
    }
};