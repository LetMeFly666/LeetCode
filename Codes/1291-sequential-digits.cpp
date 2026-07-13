/*
 * @Author: LetMeFly
 * @Date: 2026-07-13 21:54:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-13 21:56:25
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            int v = i;
            for (int j = i + 1; j <= 9; j++) {
                v = v * 10 + j;
                if (low <= v && v <= high) {
                    ans.push_back(v);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
