/*
 * @Author: LetMeFly
 * @Date: 2026-07-07 22:09:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-07 22:16:53
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int ans = intervals.size();
        for (int i = 0, n = intervals.size(), r = 0; i < n; i++) {
            ans -= intervals[i][1] <= r;
            r = max(r, intervals[i][1]);
        }
        return ans;
    }
};
