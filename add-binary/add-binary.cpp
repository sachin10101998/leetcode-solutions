#include<bits/stdc++.h>
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        string smaller;
        int l_s;
        int l_l;
        string larger;
        if(n<m) {
            smaller = a;
            l_s = a.size();
            larger = b;
            l_l = b.size();
        } else {
            smaller = b;
            l_s = b.size();
            larger = a;
            l_l = a.size();
        }
        int diff = l_l-l_s;
        string zeros = "";
        for(int i=0;i<diff;i++){
            zeros+="0";
        }
        cout<<"Zeros is"<<zeros;
        cout<<"Smaller is"<< smaller;
        smaller=zeros+smaller;
        cout<<"Larger is"<< larger;
        cout<<"Smaller is "<<smaller;
        return solve(larger, smaller);
        
    }
    // 11
    // 01
    string solve(string a , string b){
        cout<<endl;
        int carry = 0;
        string x = "";
        cout<<"Size is"<< a.length();
        for(int i=a.length()-1;i>=0;i--){
            int temp1 = a[i]-'0';
            cout<<"a[i] is "<<a[i]<<endl;
            cout<<"Temp1 is "<< temp1<<endl;
            int temp2 = b[i]-'0';
            cout<<"Temp2 is "<< temp2<<endl;
            int temp3 = temp1+temp2;
            cout<<"Temp3 is "<< temp3<<"and carry is "<<carry<<endl;
            if(temp3==0){
                if(carry==0){
                    x.insert(0, "0");
                } else if(carry==1){
                    x.insert(0, "1");
                    carry = 0;
                }
            } else if(temp3==1){
                if(carry == 0){
                    x.insert(0, "1");
                } else if(carry == 1){
                    x.insert(0, "0");
                    carry =1;
                } 
            } else if(temp3==2){
                if(carry==0){
                    x.insert(0, "0");
                    carry = 1;
                } else if(carry ==1 ){
                    x.insert(0, "1");  
                }
            }
        }
        if(carry == 1){
            x.insert(0,"1");
        }
        return x;
    }
};