/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 20:05:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 20:39:45
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> res(n, -1);
    stack<int> st;
    
    // 从左到右处理，计算右边更大的鱼吃掉当前鱼所需的次数
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) {
            if (res[st.top()] == -1) {
                res[st.top()] = 1;
            } else {
                res[st.top()] = min(res[st.top()], 1);
            }
            st.pop();
        }
        st.push(i);
    }
    
    // 清空栈，从右到左处理，计算左边更大的鱼吃掉当前鱼所需的次数
    while (!st.empty()) st.pop();
    
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] < a[i]) {
            if (res[st.top()] == -1) {
                res[st.top()] = 1;
            } else {
                res[st.top()] = min(res[st.top()], 1);
            }
            st.pop();
        }
        st.push(i);
    }
    
    // 现在需要处理更复杂的情况，考虑间接被吃的情况
    // 重新使用单调栈来找到每个元素左右第一个更大的元素
    vector<int> left(n, -1), right(n, -1);
    
    // 找左边第一个更大的元素
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            left[i] = st.top();
        }
        st.push(i);
    }
    
    // 找右边第一个更大的元素
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right[i] = st.top();
        }
        st.push(i);
    }
    
    // 根据左右更大的元素来计算最终答案
    for (int i = 0; i < n; i++) {
        if (left[i] != -1 && right[i] != -1) {
            // 左右都有更大的鱼，需要2次操作
            res[i] = 2;
        } else if (left[i] != -1 || right[i] != -1) {
            // 只有一边有更大的鱼，需要1次操作
            res[i] = 1;
        }
        // 否则 res[i] 保持为 -1，表示不会被吃掉
    }
    
    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}
/*
大鱼吃小鱼游戏，共n条鱼编号1到n，血量a[i]
游戏规则：一条鱼的血量严格大于（不包含等于）它相邻的鱼时，可以吃掉相邻的鱼并增加自身血量，增加血量为被吃掉的鱼的血量。没有任何一条鱼血量严格大于它的邻居时，游戏结束。
请问：对于每一条鱼，计算在所有可能的进食顺序中，它被其他鱼吃掉所需要的最少次数是多少？若它不可能被吃掉，则输出-1

输入：
第一行一个正整数n（1<=n<=100000）
第二行n个正整数a[i]（1<=a[i]<=100000）
保证n条鱼血量之和不会超过10^10

输出：
n个整数，第i个整数表示编号为i的鱼被其他鱼吃掉所需要的最少次数；若不可能被吃掉，则输出-1。

如：
4
3 2 4 2
输出
2 1 2 1

如：
5
2 2 3 1 1
输出：
2 1 -1 1 2

*/
