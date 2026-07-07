/*
 * @Author: LetMeFly
 * @Date: 2026-07-07 22:09:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-07 22:11:33
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = intervals.size();
        for (int i = 0, n = intervals.size(), r = 0; i < n; i++) {
            ans -= intervals[i][1] <= r;
            r = max(r, intervals[i][1]);
        }
        return ans;
    }
};
