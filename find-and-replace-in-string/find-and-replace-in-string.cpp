class Solution {
public:
    bool check(int start,string&source,string&S){
    if(start+source.size()>S.size()){return false;}
    for(int i=0;i<source.size();i++){
        if(S[start+i]!=source[i]){return false;}
    }
    return true;
}
string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets){
    map<int,int>helper;
    int n = indexes.size();
    for(int i=0;i<n;i++){
        if(check(indexes[i],sources[i],S)==false){continue;}
        helper[indexes[i]] = i;
    }
    string result;
    auto it = helper.begin();
    for(int i=0;i<S.size();i++){
        if(it!=helper.end()&&i==it->first){//need to be deleted
            result += targets[it->second];
            i += (sources[it->second].size() - 1);//we go to the index which is part of our resulting string
            it++;//getting next source[i] to be deleted
        }
        else{
            result.push_back(S[i]);//we don't delete it is part of resulting string
        }
    }
    return result;
}
};