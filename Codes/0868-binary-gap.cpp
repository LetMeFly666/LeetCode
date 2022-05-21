/*
 * @Author: LetMeFly
 * @Date: 2022-04-24 16:19:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-24 16:20:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        vector<int> locs;
        int cnt = 0;
        while (n) {
            if (n & 1) {
                locs.push_back(cnt);
            }
            cnt++, n /= 2;
        }
        for (int i = 1; i < locs.size(); i++) {
            ans = max(ans, locs[i] - locs[i - 1]);
        }
        return ans;
    }
};