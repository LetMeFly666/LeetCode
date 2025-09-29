/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 20:05:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 20:18:26
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
    int eatenBy; // 被哪条鱼吃掉
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
    vector<int> result(n, -1);
    vector<int> steps(n, 0); // 记录被吃掉的步数
    
    // 初始化双向链表
    for (int i = 0; i < n; i++) {
        nodes[i] = {i, a[i], i - 1, i + 1, true, -1};
    }
    
    // 使用小顶堆，按值从小到大处理
    auto cmp = [](pair<int, long long> a, pair<int, long long> b) {
        return a.second > b.second;
    };
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cmp)> pq(cmp);
    
    for (int i = 0; i < n; i++) {
        pq.push({i, a[i]});
    }
    
    int currentStep = 0;
    
    while (!pq.empty()) {
        currentStep++;
        auto [idx, val] = pq.top();
        pq.pop();
        
        if (!nodes[idx].alive || nodes[idx].val != val) continue;
        
        int left = nodes[idx].left;
        int right = nodes[idx].right;
        
        // 检查当前鱼是否能被吃掉
        if (left >= 0 && nodes[left].alive && nodes[left].val > val) {
            // 被左边鱼吃掉
            if (result[idx] == -1) {
                result[idx] = currentStep;
                nodes[idx].alive = false;
                nodes[idx].eatenBy = left;
                
                // 更新链表
                if (left >= 0) {
                    nodes[left].right = right;
                }
                if (right < n) {
                    nodes[right].left = left;
                }
                
                // 左边的鱼血量增加
                nodes[left].val += val;
                pq.push({left, nodes[left].val});
            }
        } 
        else if (right < n && nodes[right].alive && nodes[right].val > val) {
            // 被右边鱼吃掉
            if (result[idx] == -1) {
                result[idx] = currentStep;
                nodes[idx].alive = false;
                nodes[idx].eatenBy = right;
                
                // 更新链表
                if (left >= 0) {
                    nodes[left].right = right;
                }
                if (right < n) {
                    nodes[right].left = left;
                }
                
                // 右边的鱼血量增加
                nodes[right].val += val;
                pq.push({right, nodes[right].val});
            }
        }
        // 如果当前鱼不能立即被吃掉，重新加入队列等待后续处理
        else if (result[idx] == -1) {
            pq.push({idx, val});
        }
    }
    
    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << result[i];
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