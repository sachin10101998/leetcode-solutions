class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_index = -1;
        int max_value = -1;
        for(int i=0;i<candies.size();i++){
            if(candies[i]>max_value){
                max_value = candies[i];
                max_index = i;
            }
        }
        vector<bool>result(candies.size());
        for(int i=0;i<candies.size();i++){
            int curr_val = candies[i];
            if(curr_val+extraCandies>=max_value){
                result[i]=true;
            } else{
                result[i]=false;
            }
        }
        return result;
    }
};