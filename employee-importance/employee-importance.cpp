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
    int answer=0;
 
    int getImportance(vector<Employee*> employees, int id) {
        for(int i=0;i<employees.size();i++){
            if(employees[i]->id==id){
                answer+=employees[i]->importance;
                vector<int> temp = employees[i]->subordinates;
                for(int j=0;j<temp.size();j++){
                    getImportance(employees, temp[j]);
                }
            }
        }
        return answer;
    }
};