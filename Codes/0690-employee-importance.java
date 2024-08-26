/*
 * @Author: LetMeFly
 * @Date: 2024-08-26 23:46:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-26 23:52:50
 */
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.Queue;
import java.util.LinkedList;

// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};


class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> table = new HashMap<Integer, Employee>();
        for (Employee thisEmployee : employees) {
            table.put(thisEmployee.id, thisEmployee);
        }
        int ans = 0;
        Queue<Employee> q = new LinkedList<Employee>();
        q.add(table.get(id));
        while (!q.isEmpty()) {
            Employee thisEmployee = q.poll();
            ans += thisEmployee.importance;
            for (int nextId : thisEmployee.subordinates) {
                q.add(table.get(nextId));
            }
        }
        return ans;
    }
}