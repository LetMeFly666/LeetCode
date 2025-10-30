/*
 * @Author: LetMeFly
 * @Date: 2025-10-25 21:01:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-25 21:01:55
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> rollback(vector<vector<int>>& dp_prev, vector<int>& len, vector<int>& a, int start) {
    vector<int> ans;
    do {
        ans.push_back(a[start]);
        // 找到能提供最大契合度的前驱
        int best_prev = -1;
        for (int p : dp_prev[start]) {
            if (best_prev == -1 || len[p] > len[best_prev]) {
                best_prev = p;
            }
        }
        start = best_prev;
    } while (start != -1);
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<vector<int>> getAllMaxUp(vector<int>& a, unordered_set<int>& se) {
    int n = a.size();
    vector<int> len(n, 1);  // 长度
    vector<int> rare(n, 0); // 稀有宝石数量
    vector<vector<int>> dp_prev(n);  // 存储所有可能的前驱
    
    int maxLength = 1;
    for (int i = 0; i < n; i++) {
        rare[i] = se.count(a[i]) ? 1 : 0; // 当前宝石是否为稀有
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                if (len[j] + 1 > len[i]) {
                    len[i] = len[j] + 1;
                    rare[i] = rare[j] + (se.count(a[i]) ? 1 : 0);
                    dp_prev[i].clear();
                    dp_prev[i].push_back(j);
                    maxLength = max(maxLength, len[i]);
                } else if (len[j] + 1 == len[i]) {
                    // 长度相同时，保留稀有宝石更多的前驱
                    int new_rare = rare[j] + (se.count(a[i]) ? 1 : 0);
                    if (new_rare > rare[i]) {
                        rare[i] = new_rare;
                        dp_prev[i].clear();
                        dp_prev[i].push_back(j);
                    } else if (new_rare == rare[i]) {
                        dp_prev[i].push_back(j);
                    }
                }
            }
        }
    }
    
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        if (len[i] == maxLength) {
            ans.push_back(rollback(dp_prev, rare, a, i));
        }
    }
    return ans;
}

int maxSame(vector<int>& a, unordered_set<int>& b) {
    int ans = 0;
    for (int t : a) {
        ans += b.count(t);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    unordered_set<int> se;
    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        se.insert(y);
    }
    
    vector<vector<int>> ups = getAllMaxUp(a, se);
    
    int ans = 0;
    for (vector<int>& seq : ups) {
        ans = max(ans, maxSame(seq, se));
    }
    cout << ans << endl;
    
    return 0;
}