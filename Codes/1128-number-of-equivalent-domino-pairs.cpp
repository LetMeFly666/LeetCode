/*
 * @Author: LetMeFly
 * @Date: 2025-05-04 14:26:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-04 14:32:17
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int pair2int(vector<int>& v) {
        return (v[0] - 1) * 9 + (v[1] - 1);
    }

    inline int reverseNum(int i) {
        int a = i % 9, b = i / 9;
        return a * 9 + b;
    }
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int times[81] = {0};
        for (vector<int>& v : dominoes) {
            times[pair2int(v)]++;
        }
        int ans = 0;
        for (int i = 0; i < 81; i++) {
            int r = reverseNum(i);
            ans += times[r] + times[i] * (times[i] - 1);
        }
        return ans / 2;
    }
};