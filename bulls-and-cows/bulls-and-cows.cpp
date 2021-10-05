class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_multiset<char>secret_chars;
        for(auto x: secret){
            secret_chars.insert(x);
        }
        int n = secret.length();
        unordered_set<int>correct;
        int bull = 0;
        int cows =0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bull++;
                correct.insert(i);
                secret_chars.erase(secret_chars.find(secret[i]));
            }
        }
        for(int i=0;i<n;i++){
            if(secret[i]!=guess[i]&&secret_chars.find(guess[i])!=secret_chars.end()){
                secret_chars.erase(secret_chars.find(guess[i]));
                cows++;
            }
        }
        return to_string(bull)+"A"+to_string(cows)+"B";
        
    }
};