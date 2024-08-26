/*
 * @Author: LetMeFly
 * @Date: 2024-08-26 23:38:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-26 23:43:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> table;
        for (Employee* thisEmployee : employees) {
            table[thisEmployee->id] = thisEmployee;
        }
        int ans = 0;
        queue<Employee*> q;
        q.push(table[id]);
        while (q.size()) {
            Employee* thisEmployee = q.front();
            q.pop();
            ans += thisEmployee->importance;
            for (int nextEmployeeId : thisEmployee->subordinates) {
                q.push(table[nextEmployeeId]);
            }
        }
        return ans;
    }
};