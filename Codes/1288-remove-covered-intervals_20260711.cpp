/*
 * @Author: LetMeFly
 * @Date: 2026-07-11 07:59:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-11 08:01:03
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int ans = intervals.size();
        int maxr = 0;
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
