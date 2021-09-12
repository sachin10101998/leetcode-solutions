class Solution {
public:
    
    long long factorial(long long a){
        if(a==1||a==0){
            return 1;
        }
        else {
            return a*factorial(a-1);
        }
    }
    
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<long long,long long>,long long>m1;
        for(long long i=0;i<rectangles.size();i++){
            long long w = rectangles[i][0];
            long long h = rectangles[i][1];
            long long hcf = gcd(w,h);
            w/=hcf;
            h/=hcf;
            m1[{w,h}]++;
        }
        map<pair<long long,long long>,long long> :: iterator itr;
        long long answer =0;
        for(itr = m1.begin();itr!=m1.end();itr++){
            long long temp = itr->second;
            if(temp>=2){
                long long temp2 = temp-2;
                answer+=(temp*(temp-1))/2;
            }
            
            
        }
        return answer;
    }
};