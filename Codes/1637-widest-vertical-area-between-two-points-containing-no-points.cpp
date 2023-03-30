/*
 * @Author: LetMeFly
 * @Date: 2023-03-30 09:06:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-30 09:07:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> se;
        for (vector<int>& point : points) {
            se.insert(point[0]);
        }
        int ans = 0;
        int last = *se.begin();
        for (int t : se) {
            ans = max(ans, t - last);
            last = t;
        }
        return ans;
    }
};