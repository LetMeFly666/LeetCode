/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 20:05:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 20:13:54
 */
#include <bits/stdc++.h>
using namespace std;

struct Fish {
    int index;
    long long health;
    int left, right;
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

    vector<Fish> fishes(n);
    vector<int> result(n, -1);
    for (int i = 0; i < n; i++) {
        fishes[i] = {i, a[i], i - 1, i + 1};
    }
    
    // 血量小优先
    auto cmp = [](const pair<int, long long>& a, const pair<int, long long>& b) {
        return a.second > b.second;
    };
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cmp)> pq(cmp);
    
    for (int i = 0; i < n; i++) {
        pq.push({i, a[i]});
    }
    
    vector<bool> alive(n, true);
    int step = 0;
    while (!pq.empty()) {
        auto [idx, health] = pq.top();
        pq.pop();
        if (!alive[idx] || fishes[idx].health != health) {
            continue;
        }
        int left = fishes[idx].left;
        int right = fishes[idx].right;

        // 能否被吃
        bool canBeEaten = false;
        if (left >= 0 && alive[left] && fishes[left].health > health) {
            canBeEaten = true;
            if (result[idx] == -1) {
                result[idx] = step + 1;
            }
        }
        if (right < n && alive[right] && fishes[right].health > health) {
            canBeEaten = true;
            if (result[idx] == -1) {
                result[idx] = step + 1;
            }
        }
        
        // 这条鱼能吃掉邻居
        if ((left >= 0 && alive[left] && health > fishes[left].health) || 
            (right < n && alive[right] && health > fishes[right].health)) {
            // 优先吃血量较小的邻居
            long long leftHealth = (left >= 0 && alive[left]) ? fishes[left].health : 1e18;
            long long rightHealth = (right < n && alive[right]) ? fishes[right].health : 1e18;
            
            if (leftHealth < rightHealth && leftHealth < health) {
                // 吃左边
                fishes[idx].health += leftHealth;
                alive[left] = false;
                fishes[idx].left = fishes[left].left;
                if (fishes[idx].left >= 0) {
                    fishes[fishes[idx].left].right = idx;
                }
                pq.push({idx, fishes[idx].health});
            } else if (rightHealth < health) {
                // 吃右边
                fishes[idx].health += rightHealth;
                alive[right] = false;
                fishes[idx].right = fishes[right].right;
                if (fishes[idx].right < n) {
                    fishes[fishes[idx].right].left = idx;
                }
                pq.push({idx, fishes[idx].health});
            }
        }
        
        step++;
    }
    
    for (int i = 0; i < n; i++) {
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