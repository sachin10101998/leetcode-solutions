class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i=1;i<=100;i++){
            squares.push_back(i*i);
        }
        queue<int>q;
        q.push(n);
        int res = 0;
        map<int,int>m1;
        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                int frontKey = q.front();
                q.pop();
                for(int j=1;j*j<=frontKey;j++){
                    if(frontKey-j*j==0){
                        return res+1;
                    }
                    else {
                        if(m1.find(frontKey-j*j)!=m1.end()){
                            continue;
                        } else {
                            q.push(frontKey-j*j);
                            m1[frontKey-j*j]=1;
                        }
                    }
                }
            }
            res+=1;
        }
        return -1;
    }
};