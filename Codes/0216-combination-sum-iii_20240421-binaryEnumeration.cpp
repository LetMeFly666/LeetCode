/*
 * @Author: LetMeFly
 * @Date: 2024-04-21 13:35:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-21 13:37:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int to = 1 << 9;
        for (int i = 0; i < to; i++) {
            if (__builtin_popcount(i) != k) {
                continue;
            }
            vector<int> thisSolution;
            int thisCnt = 0;
            for (int j = 0; j < 9; j++) {
                if (i & (1 << j)) {
                    thisCnt += j + 1;
                    thisSolution.push_back(j + 1);
                }
            }
            if (thisCnt == n) {
                ans.push_back(thisSolution);
            }
        }
        return ans;
    }
};