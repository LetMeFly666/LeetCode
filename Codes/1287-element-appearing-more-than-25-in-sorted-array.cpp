/*
 * @Author: LetMeFly
 * @Date: 2025-02-17 14:38:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-17 14:42:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int locDiff = arr.size() / 4;
        for (int i = 0; 1; i++) {
            if (arr[i] == arr[i + locDiff]) {
                return arr[i];
            }
        }
    }
};