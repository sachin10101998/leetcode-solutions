class Solution {
public:
    vector<int>representatives;
    vector<int>size;
    int find(int u){
        if(u==representatives[u]){
            return u;
        }
        else{
            return representatives[u]=find(representatives[u]);
        }
    }
    void combine(int u , int v){
        u = find(u);
        v = find(v);
        if(u==v){
            return ;
        }
        if(size[u]>size[v]){
            representatives[v]=u;
            size[u]+=size[v];
        }
        else{
            representatives[u]=v;
            size[v]+=size[u];
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        representatives.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            representatives[i]=i;
            size[i]=1;
        }
        int c = edges.size();
        for(int i=0;i<c;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            u = find(u);
            v = find(v);
            if(u==v){
                return false;
            } else{
                combine(u,v);
            }
        }
        set<int>s1;
        for(int i=0;i<representatives.size();i++){
            cout<<representatives[i]<<" ";
            s1.insert(find(representatives[i]));
        }
        if(s1.size()!=1){
            return false;
        }
        return true;
    }
};