/*
 * @Author: LetMeFly
 * @Date: 2024-10-01 15:54:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-01 16:00:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    unordered_map<int, int> cache;
    unordered_set<int> se;
    vector<int> costs;
    int dfs(int day) {
        if (day <= 0) {
            return 0;
        }
        if (cache.count(day)) {
            return cache[day];
        }
        if (!se.count(day)) {
            return cache[day] = dfs(day - 1);
        }
        return cache[day] = min(dfs(day - 1) + costs[0], min(dfs(day - 7) + costs[1], dfs(day - 30) + costs[2]));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->costs = costs;
        se.insert(days.begin(), days.end());
        return dfs(days.back());
    }
};