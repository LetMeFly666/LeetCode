/*
 * @Author: LetMeFly
 * @Date: 2021-12-19 08:38:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-19 08:45:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> cannotHim(n);
        vector<int> cntHim(n);
        for (vector<int>& v : trust) {
            cannotHim[v[0] - 1] = true;
            cntHim[v[1] - 1]++;
        }
        for (int i = 0; i < n; i++) {
            if (!cannotHim[i] && cntHim[i] == n - 1) {
                return i + 1;
            }
        }
        return -1;
    }
};