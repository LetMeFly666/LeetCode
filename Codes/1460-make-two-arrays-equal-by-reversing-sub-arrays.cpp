/*
 * @Author: LetMeFly
 * @Date: 2022-08-24 10:23:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-24 10:23:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for (int i = target.size() - 1; i >= 0; i--) {
            if (target[i] != arr[i]) {
                return false;
            }
        }
        return true;
    }
};