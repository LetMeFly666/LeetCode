/*
 * @Author: LetMeFly
 * @Date: 2025-12-23 13:34:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-23 18:58:01
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<pair<int, int>> maxValue;
        int singleMax = 0, pairMax = 0;
        for (vector<int>& e : events) {
            vector<pair<int, int>>::iterator it = lower_bound(maxValue.begin(), maxValue.end(), e[0], [](const pair<int, int>& p, int value) {
                return p.first < value;
            });
            if (it != maxValue.begin()) {
                pairMax = max(pairMax, (--it)->second + e[2]);
            }
            singleMax = max(singleMax, e[2]);
            maxValue.push_back({e[1], singleMax});
        }
        return max(pairMax, singleMax);
    }
};