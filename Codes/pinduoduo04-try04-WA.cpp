/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 20:05:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 20:21:31
 */
/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 20:05:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 20:19:16
 */
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

vector<int> calculateMinEatTimes(int n, vector<long long>& a) {
    vector<int> result(n, -1); // 初始化为-1，表示不可能被吃掉
    
    // 双向单调栈，用于寻找每个位置左右第一个比它大的元素
    stack<int> leftStack, rightStack;
    
    // 从左到右处理，寻找右边第一个比当前元素大的元素
    vector<int> rightGreater(n, -1);
    for (int i = 0; i < n; ++i) {
        while (!rightStack.empty() && a[i] > a[rightStack.top()]) {
            rightGreater[rightStack.top()] = i;
            rightStack.pop();
        }
        rightStack.push(i);
    }
    
    // 从右到左处理，寻找左边第一个比当前元素大的元素
    vector<int> leftGreater(n, -1);
    for (int i = n - 1; i >= 0; --i) {
        while (!leftStack.empty() && a[i] > a[leftStack.top()]) {
            leftGreater[leftStack.top()] = i;
            leftStack.pop();
        }
        leftStack.push(i);
    }
    
    // 使用动态规划计算每条鱼被吃掉的最少次数
    vector<int> dp(n, -1);
    
    // 对于每条鱼，检查它是否可能被吃掉
    for (int i = 0; i < n; ++i) {
        // 如果左右都没有比它大的鱼，那么它不可能被吃掉
        if (leftGreater[i] == -1 && rightGreater[i] == -1) {
            continue;
        }
        
        int minTimes = INT_MAX;
        // 检查左边的鱼是否能吃掉它
        if (leftGreater[i] != -1) {
            int j = leftGreater[i];
            int times = 1;
            // 寻找从左边鱼到当前鱼的最短路径
            while (j < i) {
                if (rightGreater[j] != -1 && rightGreater[j] <= i) {
                    j = rightGreater[j];
                    times++;
                } else {
                    break;
                }
            }
            minTimes = times;
        }
        
        // 检查右边的鱼是否能吃掉它
        if (rightGreater[i] != -1) {
            int j = rightGreater[i];
            int times = 1;
            // 寻找从右边鱼到当前鱼的最短路径
            while (j > i) {
                if (leftGreater[j] != -1 && leftGreater[j] >= i) {
                    j = leftGreater[j];
                    times++;
                } else {
                    break;
                }
            }
            minTimes = min(minTimes, times);
        }
        
        dp[i] = minTimes;
    }
    
    return dp;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> result = calculateMinEatTimes(n, a);
    for (int i = 0; i < n; ++i) {
        cout << result[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}
/*
大鱼吃小鱼游戏，共n条鱼编号1到n，血量a[i]
游戏规则：一条鱼的血量严格大于（不包含等于）它相邻的鱼时，可以吃掉相邻的鱼并增加自身血量，增加血量为被吃掉的鱼的血量。没有任何一条鱼血量严格大于它的邻居时，游戏结束。
请问：对于每一条鱼，计算在所有可能的进食顺序中，它被其他鱼吃掉所需要的最少次数是多少？若它不可能被吃掉，则输出-1

第一行一个正整数n（1<=n<=100000）
第二行n个正整数a[i]（1<=a[i]<=100000）
保证n条鱼血量之和不会超过10^10

如：
4
3 2 4 2
输出
2 1 2 1
*/
