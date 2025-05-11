/*
 * @Author: LetMeFly
 * @Date: 2025-05-11 14:00:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-11 14:13:46
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] % 2 && arr[i - 1] % 2 && arr[i - 2] % 2) {
                return true;
            }
        }
        return false;
    }
};