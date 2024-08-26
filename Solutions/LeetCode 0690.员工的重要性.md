---
title: 690.员工的重要性
date: 2024-08-27 00:14:33
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, BFS, 数组, 数据结构, 哈希表, 哈希, set]
---

# 【LetMeFly】690.员工的重要性：哈希表+广度优先搜索

力扣题目链接：[https://leetcode.cn/problems/employee-importance/](https://leetcode.cn/problems/employee-importance/)

<p>你有一个保存员工信息的数据结构，它包含了员工唯一的 id ，重要度和直系下属的 id 。</p>

<p>给定一个员工数组&nbsp;<code>employees</code>，其中：</p>

<ul>
	<li><code>employees[i].id</code> 是第&nbsp;<code>i</code>&nbsp;个员工的 ID。</li>
	<li><code>employees[i].importance</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个员工的重要度。</li>
	<li><code>employees[i].subordinates</code> 是第 <code>i</code> 名员工的直接下属的 ID 列表。</li>
</ul>

<p>给定一个整数&nbsp;<code>id</code>&nbsp;表示一个员工的 ID，返回这个员工和他所有下属的重要度的 <strong>总和</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://pic.leetcode.cn/1716170448-dKZffb-image.png" style="width: 400px; height: 258px;" /></strong></p>

<pre>
<strong>输入：</strong>employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
<strong>输出：</strong>11
<strong>解释：</strong>
员工 1 自身的重要度是 5 ，他有两个直系下属 2 和 3 ，而且 2 和 3 的重要度均为 3 。因此员工 1 的总重要度是 5 + 3 + 3 = 11 。
</pre>

<p>&nbsp;</p>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://pic.leetcode.cn/1716170929-dkWpra-image.png" style="width: 362px; height: 361px;" /></strong></p>

<pre>
<strong>输入：</strong>employees = [[1,2,[5]],[5,-3,[]]], id = 5
<strong>输出：</strong>-3
<strong>解释：</strong>员工 5 的重要度为 -3 并且没有直接下属。
因此，员工 5 的总重要度为 -3。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= employees.length &lt;= 2000</code></li>
	<li><code>1 &lt;= employees[i].id &lt;= 2000</code></li>
	<li>所有的&nbsp;<code>employees[i].id</code>&nbsp;<strong>互不相同</strong>。</li>
	<li><code>-100 &lt;= employees[i].importance &lt;= 100</code></li>
	<li>一名员工最多有一名直接领导，并可能有多名下属。</li>
	<li><code>employees[i].subordinates</code>&nbsp;中的 ID 都有效。</li>
</ul>


    
## 解题方法：哈希表+广度优先搜索

因为要多次依据员工id获取员工信息，因此可以二话不说建立一个哈希表。

接着只需要一个广度优先搜索，从id这个员工开始，出队时累加重要程度并将所有子员工入队，直至队列为空。

+ 时间复杂度$O(len(employees))$
+ 空间复杂度$O(len(employees))$

### AC代码

#### Python

```python
from typing import List

# # Definition for Employee.
# class Employee:
#     def __init__(self, id: int, importance: int, subordinates: List[int]):
#         self.id = id
#         self.importance = importance
#         self.subordinates = subordinates

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        table = dict()
        for e in employees:
            table[e.id] = e
        ans = 0
        q:List['Employee'] = [table[id]]
        while q:
            this = q.pop()
            ans += this.importance
            for next in this.subordinates:
                q.append(table[next])
        return ans
```

#### C++

```cpp
// // Definition for Employee.
// class Employee {
// public:
//     int id;
//     int importance;
//     vector<int> subordinates;
// };

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
```

#### Java

```java
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.Queue;
import java.util.LinkedList;

// // Definition for Employee.
// class Employee {
//     public int id;
//     public int importance;
//     public List<Integer> subordinates;
// };


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
```

#### Golang

```go
package main

import "container/list"  // 其实是一个列表

// // Definition for Employee.
// type Employee struct {
//     Id int
//     Importance int
//     Subordinates []int
// }

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
```
## End

不得不说，这题员工的重要程度还有负数，也忒损了。

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/27/LeetCode%200690.%E5%91%98%E5%B7%A5%E7%9A%84%E9%87%8D%E8%A6%81%E6%80%A7/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141576521](https://letmefly.blog.csdn.net/article/details/141576521)
