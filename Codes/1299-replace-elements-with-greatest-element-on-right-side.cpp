/*
 * @Author: LetMeFly
 * @Date: 2025-02-16 10:21:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-16 10:22:18
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int M = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int nM = max(M, arr[i]);
            arr[i] = M;
            M = nM;
        }
        return arr;
    }
};