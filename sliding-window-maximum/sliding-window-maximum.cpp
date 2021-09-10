class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int i =0;
        int j = k-1;
        multiset<int, greater<int>>m1;
        for(int i=0;i<k;i++){
            m1.insert(nums[i]);
        }
        multiset<int>::iterator itr;
        for(itr = m1.begin();itr!=m1.end();itr++){
            cout<<*itr<<" ";
        }
        cout<<endl;
        itr = m1.begin();
        ans.push_back(*itr);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        while(j<nums.size()-1){
            int temp = nums[i];
            i++;
            j++;
            m1.erase(m1.find(temp));
            m1.insert(nums[j]);
            itr = m1.begin();
            ans.push_back(*itr);
        }
        return ans;
    }
};