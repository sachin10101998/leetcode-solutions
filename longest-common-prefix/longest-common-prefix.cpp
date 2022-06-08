#include<bits/stdc++.h>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int smallest = INT_MAX;
        for(int i=0;i<strs.size();i++){
            smallest = min(smallest, strs[i].size());
        }
        string res="";
        if(smallest==0){
            return res;
        }
        for(int i=0;i<smallest;i++){
            char tem = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=tem){
                    return res;
                } else {
                    cout<<"Do Nothing!";
                }
            }
            res+=tem;
        }
        return res;
    }
    
    int min(int a , int b){
        if(a<b){
            return a;
        } else{
            return b;
        }
    }
};