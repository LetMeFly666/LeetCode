/*
 * @Author: LetMeFly
 * @Date: 2026-05-12 16:30:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-12 16:33:29
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] - a[0] < b[1] - b[0];
        });
        int ans = 0, now = 0;
        for (vector<int>& task : tasks) {
            if (now < task[1]) {
                int need = task[1] - now;
                now = task[1];
                ans += need;
            }
            now -= task[0];
        }
        return ans;
    }
};
