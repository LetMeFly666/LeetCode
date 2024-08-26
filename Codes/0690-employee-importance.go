/*
 * @Author: LetMeFly
 * @Date: 2024-08-26 23:55:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-27 00:10:03
 */
package main

import "container/list"  // 其实是一个列表

// Definition for Employee.
type Employee struct {
    Id int
    Importance int
    Subordinates []int
}

func getImportance(employees []*Employee, id int) int {
    table := map[int]*Employee{};
    for _, thisEmployee := range employees {
        table[thisEmployee.Id] = thisEmployee;
    }
    ans := 0
    q := list.New()
    q.PushBack(table[id])
    for q.Len() > 0 {
        thisEmployee := q.Front()
        q.Remove(thisEmployee)
        ans += thisEmployee.Value.(*Employee).Importance
        for _, nextId := range thisEmployee.Value.(*Employee).Subordinates {
            q.PushBack(table[nextId])
        }
    }
    return ans
}