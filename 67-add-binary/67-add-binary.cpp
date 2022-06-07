#include<bits/stdc++.h>
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        if(n<m){
            return solve(b, a);
        } else {
            return solve(a,b);
        }
        
    }

    string solve(string a , string b){
        int diff = a.length()-b.length();
        string zeros = "";
        for(int i=0;i<diff;i++){
            zeros+="0";
        }
        b=zeros+b;
        int carry = 0;
        string x = "";
        cout<<"Size is"<< a.length();
        for(int i=a.length()-1;i>=0;i--){
            int temp1 = a[i]-'0';
            int temp2 = b[i]-'0';
            int temp3 = temp1+temp2;
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