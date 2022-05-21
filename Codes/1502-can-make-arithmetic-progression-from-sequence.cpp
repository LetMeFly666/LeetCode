/*
 * @Author: LetMeFly
 * @Date: 2022-04-10 08:42:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-10 08:43:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2]) {
                return false;
            }
        }
        return true;
    }
};