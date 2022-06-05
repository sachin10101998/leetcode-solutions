class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1]!=9) {
            digits[digits.size()-1]=digits[digits.size()-1]+1;
            return digits;
        } else {
            if(digits.size()==1){
                digits[0]=1;
                digits.push_back(0);
                return digits;
            } else {
                for(int i=digits.size()-1;i>=0;i--){
                    if(digits[i]==9){
                        digits[i]=0;
                    } else{
                        digits[i]+=1;
                        break;
                    }
                }
                if(digits[0]==0){
                    digits.push_back(1);
                    reverse(digits.begin(), digits.end());
                }
            }
        }
        return digits;
    }
};