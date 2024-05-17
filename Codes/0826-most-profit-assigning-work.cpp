/*
 * @Author: LetMeFly
 * @Date: 2024-05-17 16:58:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-17 17:02:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> a(difficulty.size());
        for (int i = 0; i < difficulty.size(); i++) {
            a[i] = {difficulty[i], profit[i]};
        }
        sort(a.begin(), a.end());
        a.push_back({1000000, 0});
        sort(worker.begin(), worker.end());
        int M = 0;  // 能完成的任务里面收益最大的
        int ans = 0;
        for (int i = 0, it = 0; i < worker.size(); i++) {
            while (a[it].first <= worker[i]) {
                M = max(a[it].second, M);
                it++;
            }
            ans += M;
        }
        return ans;
    }
};