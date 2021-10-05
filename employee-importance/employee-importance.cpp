/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(int id, int& ans, map<int,Employee*>&m1){
        Employee* parent = m1[id];
        ans+=parent->importance;
        for(auto x: parent->subordinates){
            dfs(x,ans,m1);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> m1;
        for(auto x: employees){
            m1[x->id]=x;
        }
        int ans =0;
        dfs(id, ans, m1);
        return ans;
        
    }
};