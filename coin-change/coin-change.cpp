class Solution {
public:
    unordered_map<int, int> visited;
    
    vector<int> children(int temp, vector<int> & coins){
        vector<int> childrenset;
        for(int i=0;i<coins.size();i++){
            if(temp-coins[i]>=0 && !visited[temp - coins[i]]){
                visited[temp - coins[i]]++;
                childrenset.push_back(temp-coins[i]);
            }
        }
        return childrenset;
    }
    
    
    
    int bfs(vector<int> &coins, int amount){
        //base cases
        
        queue<int> q;
        q.push(amount);
        int l=0;
        
        while(!q.empty()){
            int ls=q.size();
            for(int i=0;i<ls;i++){
                int temp= q.front();
                q.pop();
                
                if(temp==0){
                    return l;
                }
                
                for(auto i: children(temp, coins)){
                    q.push(i);
                }
                
            }
            
            l++;
        }
      
        return -1;
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        return bfs(coins, amount);
    }
};