/*
 * @Author: LetMeFly
 * @Date: 2025-05-04 14:26:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-04 15:02:06
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int pair2int(vector<int>& v) {
        if (v[0] > v[1]) {
            return (v[1] - 1) * 9 + (v[0] - 1);
        }
        return (v[0] - 1) * 9 + (v[1] - 1);
    }
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int times[81] = {0};
        for (vector<int>& v : dominoes) {
            times[pair2int(v)]++;
        }
        int ans = 0;
        for (int i = 0; i < 81; i++) {
            ans += times[i] * (times[i] - 1) / 2;
        }
        return ans;
    }
};