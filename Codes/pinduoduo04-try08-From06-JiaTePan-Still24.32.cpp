/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 20:05:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 20:41:42
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> ans(n, -1);
    
    for (int i = 0; i < n; i++) {
        bool canBeEaten = false;
        int minSteps = n;
        
        long long power = 0;
        int steps = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] + power > a[i]) {
                canBeEaten = true;
                minSteps = min(minSteps, steps + 1);
                break;
            } else if (a[j] < a[i]) {
                power += a[j];
                steps++;
            } else {
                break;
            }
        }
        
        power = 0;
        steps = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] + power > a[i]) {
                canBeEaten = true;
                minSteps = min(minSteps, steps + 1);
                break;
            } else if (a[j] < a[i]) {
                power += a[j];
                steps++;
            } else {
                break;
            }
        }
        
        if (canBeEaten) {
            ans[i] = minSteps;
        }
    }
    
    // 特判：当所有鱼都无法被吃掉时，全部输出-1
    bool allCannotBeEaten = true;
    for (int i = 0; i < n; i++) {
        if (ans[i] != -1) {
            allCannotBeEaten = false;
            break;
        }
    }
    
    if (allCannotBeEaten) {
        // 全部输出-1（已经是默认值，无需修改）
    } else {
        // 否则按原逻辑输出结果
        for (int i = 0; i < n; i++) {
            cout << ans[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    // 如果所有鱼都无法被吃掉，输出n个-1
    if (allCannotBeEaten) {
        for (int i = 0; i < n; i++) {
            cout << "-1";
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
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
