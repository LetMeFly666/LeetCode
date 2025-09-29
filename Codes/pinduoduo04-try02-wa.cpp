/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 20:05:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 20:16:38
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int idx;
    long long val;
    int left, right;
    bool alive;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<Node> nodes(n);
    vector<int> ans(n, -1);
    
    // 初始化双向链表
    for (int i = 0; i < n; i++) {
        nodes[i] = {i, a[i], i - 1, i + 1, true};
    }
    
    // 使用小顶堆，按值从小到大处理
    auto cmp = [](pair<int, long long> a, pair<int, long long> b) {
        return a.second > b.second;
    };
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cmp)> pq(cmp);
    
    for (int i = 0; i < n; i++) {
        pq.push({i, a[i]});
    }
    
    int step = 0;
    while (!pq.empty()) {
        auto [idx, val] = pq.top();
        pq.pop();
        
        if (!nodes[idx].alive || nodes[idx].val != val) continue;
        
        int left = nodes[idx].left;
        int right = nodes[idx].right;
        
        // 检查当前鱼是否能被吃掉
        bool canBeEaten = false;
        if (left >= 0 && nodes[left].alive && nodes[left].val > val) {
            canBeEaten = true;
        }
        if (right < n && nodes[right].alive && nodes[right].val > val) {
            canBeEaten = true;
        }
        
        if (canBeEaten) {
            if (ans[idx] == -1) {
                ans[idx] = step + 1;
            }
        }
        
        // 检查当前鱼是否能吃掉邻居
        if (left >= 0 && nodes[left].alive && val > nodes[left].val) {
            // 吃掉左边的鱼
            nodes[idx].val += nodes[left].val;
            nodes[left].alive = false;
            nodes[idx].left = nodes[left].left;
            if (nodes[idx].left >= 0) {
                nodes[nodes[idx].left].right = idx;
            }
            pq.push({idx, nodes[idx].val});
        } else if (right < n && nodes[right].alive && val > nodes[right].val) {
            // 吃掉右边的鱼
            nodes[idx].val += nodes[right].val;
            nodes[right].alive = false;
            nodes[idx].right = nodes[right].right;
            if (nodes[idx].right < n) {
                nodes[nodes[idx].right].left = idx;
            }
            pq.push({idx, nodes[idx].val});
        }
        
        step++;
    }
    
    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i < n - 1) cout << " ";
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