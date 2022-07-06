class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        map<int,int> ng;
        for(int i=0;i<nums2.size();i++){
            if(s.empty()){
                s.push(nums2[i]);
            } else {
                if(s.top()>nums2[i]){
                    s.push(nums2[i]);
                } else {
                    while(!s.empty()&&s.top()<nums2[i]){
                        int x = s.top();
                        s.pop();
                        ng[x]=nums2[i];
                    }
                    s.push(nums2[i]);
                }
            }
        }
        for(int i=0;i<nums2.size();i++){
            cout<<"Next greater element for "<<nums2[i]<<" is ";
            if(ng.find(nums2[i])!=ng.end()){
                cout<<ng[nums2[i]];
            } else{
                cout<<"-1"<<endl;
            }
        }

        vector<int> result;
        for(int i=0;i<nums1.size();i++){
         if(ng.find(nums1[i])!=ng.end()){
             result.push_back(ng[nums1[i]]);
         } else {
             result.push_back(-1);
         }

            
        }
        
        return result;
    }
};