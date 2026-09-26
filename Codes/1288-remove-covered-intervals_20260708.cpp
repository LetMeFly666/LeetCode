/*
 * @Author: LetMeFly
 * @Date: 2026-07-08 11:47:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-08 11:49:29
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
        int ans = intervals.size(), maxr = 0;
        for (vector<int>& v : intervals) {
            ans -= v[1] <= maxr;
            maxr = max(maxr, v[1]);
        }
        return ans;
    }
};
