/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 20:05:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 20:32:33
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> ans(n, -1);
    
    // 对于每条鱼，检查左右两边
    for (int i = 0; i < n; i++) {
        // 检查左边
        int left_steps = 0;
        int current_power = 0;
        bool can_eat_from_left = false;
        
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > a[i]) {
                // 直接能吃掉
                left_steps = 1;
                can_eat_from_left = true;
                break;
            } else if (a[j] < a[i]) {
                // 可以被吃掉来积累能量
                current_power += a[j];
                left_steps++;
                if (current_power > a[i]) {
                    can_eat_from_left = true;
                    break;
                }
            } else {
                // 相等，无法吃掉
                break;
            }
        }
        
        // 检查右边
        int right_steps = 0;
        current_power = 0;
        bool can_eat_from_right = false;
        
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                // 直接能吃掉
                right_steps = 1;
                can_eat_from_right = true;
                break;
            } else if (a[j] < a[i]) {
                // 可以被吃掉来积累能量
                current_power += a[j];
                right_steps++;
                if (current_power > a[i]) {
                    can_eat_from_right = true;
                    break;
                }
            } else {
                // 相等，无法吃掉
                break;
            }
        }
        
        // 确定最小步数
        if (can_eat_from_left && can_eat_from_right) {
            ans[i] = min(left_steps, right_steps);
        } else if (can_eat_from_left) {
            ans[i] = left_steps;
        } else if (can_eat_from_right) {
            ans[i] = right_steps;
        }
        // 否则保持-1
    }
    
    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i < n - 1 ? " " : "\n");
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
