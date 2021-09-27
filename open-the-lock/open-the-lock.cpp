class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string>visited;
        set<string> dead_ends;
        queue<string>q1;
        q1.push("0000");
        int level = 0;
        visited.insert("0000");
        for(int i=0;i<deadends.size();i++) {
            dead_ends.insert(deadends[i]);
        }
        while(!q1.empty()){
            int size = q1.size();
            while(size>0) {
                string front = q1.front();
                q1.pop();
                if(dead_ends.find(front)!=dead_ends.end()){
                    size--;
                    continue;
                }
                if(front == target) {
                    return level;
                }
                for(int i = 0 ; i <4 ; i++) {
                    string a1 = front.substr(0,i)+to_string((front[i]=='9'? 0: front[i]-'0'+1))+ front.substr(i+1,front.length()-1);
                    string a2 = front.substr(0,i)+to_string((front[i]=='0'? 9: front[i]-'0'-1)) + front.substr(i+1,front.length()-1);
                    
                    if(visited.find(a1)==visited.end()&&dead_ends.find(a1)==dead_ends.end()){
                        q1.push(a1);
                        visited.insert(a1);
                    }
                    if(visited.find(a2)==visited.end()&&dead_ends.find(a2)==dead_ends.end()){
                        q1.push(a2);
                        visited.insert(a2);
                    }
                }
                size--;
            }
            level++;
        }
        return -1;
    }
};