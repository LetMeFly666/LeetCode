/*
 * @Author: LetMeFly
 * @Date: 2025-02-02 10:31:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-02 11:05:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (vector<int>& op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};