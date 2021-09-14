class Solution {
public:
    string getHint(string secret, string guess) {
        set<int>s1;
        int n = secret.length();
        int bulls =0;
        int cows = 0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bulls++;
                s1.insert(i);
            }
            
        }
        map<char,int>m1;
        for(int i=0;i<n;i++){
            if(s1.find(i)==s1.end()){
                m1[secret[i]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(s1.find(i)==s1.end()){
                if(m1.find(guess[i])==m1.end()){
                    continue;
                } else if(m1.find(guess[i])!=m1.end()){
                    if(m1[guess[i]]>0){
                        cows++;
                        m1[guess[i]]--;
                    }
                }
            }
        }
        string a = to_string(bulls);
        string b = to_string(cows);
        return a+"A"+b+"B";
    }
};