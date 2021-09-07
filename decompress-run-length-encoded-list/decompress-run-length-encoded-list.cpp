class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>answer;
        int i=0;
        int n = nums.size();
        while(i+1<n){
            int freq = nums[i];
            int val = nums[i+1];
            for(int j=0;j<freq;j++){
                answer.push_back(val);
            }
            i+=2;
        }
        return answer;
    }
};