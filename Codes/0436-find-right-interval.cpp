/*
 * @Author: LetMeFly
 * @Date: 2022-05-20 13:48:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-20 14:09:08
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> ma;
        for (int i = 0; i < intervals.size(); i++) {
            ma[intervals[i][0]] = i;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> ans(intervals.size());
        for (int i = 0; i < intervals.size(); i++) {
            int l = 0, r = intervals.size();
            int thisAns = -1;
            while (l < r) {
                int mid = (l + r) >> 1;
                printf("l = %d, r = %d, mid = %d\n", l, r, mid);
                if (intervals[mid][0] >= intervals[i][1]) {
                    r = mid;
                    thisAns = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            ans[ma[intervals[i][0]]] = thisAns == -1 ? -1 : ma[intervals[thisAns][0]];
        }
        return ans;
    }
};