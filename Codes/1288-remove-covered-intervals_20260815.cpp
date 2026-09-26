/*
 * @Author: LetMeFly
 * @Date: 2026-08-15 09:52:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-15 10:06:28
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int ans = intervals.size();
        int maxr = 0;
        for (vector<int>& p : intervals) {
            if (maxr >= p[1]) {
                ans--;
            } else {
                maxr = p[1];
            }
        }
        return ans;
    }
};
