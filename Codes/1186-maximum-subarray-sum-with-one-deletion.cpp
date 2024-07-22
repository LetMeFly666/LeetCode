/*
 * @Author: LetMeFly
 * @Date: 2024-07-21 19:05:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-21 19:12:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int del0 = arr[0], del1 = 0, ans = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            del1 = max(del0, del1 + arr[i]);
            del0 = max(del0 + arr[i], arr[i]);
            ans = max(ans, max(del0, del1));
        }
        return ans;
    }
};