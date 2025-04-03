/*
 * @Author: LetMeFly
 * @Date: 2025-04-03 23:18:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-03 23:24:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
private:
    vector<vector<int>> q;
    unordered_map<int, ll> cache;

    ll dfs(int n) {
        if (n >= q.size()) {
            return 0;
        }
        if (cache.count(n)) {
            return cache[n];
        }
        return cache[n] = max(dfs(n + 1), dfs(n + q[n][1] + 1) + q[n][0]);
    }
public:
    ll mostPoints(vector<vector<int>>& questions) {
        q = move(questions);
        return dfs(0);
    }
};