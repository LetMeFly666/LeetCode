/*
 * @Author: LetMeFly
 * @Date: 2026-10-23 21:05:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-23 21:07:57
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
        for (vector<int>& v : intervals) {
            if (v[1] <= maxr) {
                ans--;
            } else {
                maxr = v[1];
            }
        }
        return ans;
    }
};
