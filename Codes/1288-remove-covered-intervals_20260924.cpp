/*
 * @Author: LetMeFly
 * @Date: 2026-09-24 12:11:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-24 12:14:10
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
        int maxr = -1;
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
