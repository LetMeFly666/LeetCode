/*
 * @Author: LetMeFly
 * @Date: 2023-10-27 12:24:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-27 12:29:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    long long getMax(int l, vector<int>& v) {
        sort(v.begin(), v.end());
        int ans= 0;
        for (int i = 1; i < v.size(); i++) {
            ans = max(ans, v[i] -  v[i - 1]);
        }
        return max(ans, max(v[0], l - v[v.size() - 1]));
    }

public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return getMax(h, horizontalCuts) *  getMax(w, verticalCuts) % 1000000007;
    }
};