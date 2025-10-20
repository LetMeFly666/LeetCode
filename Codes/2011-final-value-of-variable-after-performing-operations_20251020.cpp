/*
 * @Author: LetMeFly
 * @Date: 2025-10-20 18:44:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-20 18:46:29
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (string& op : operations) {
            ans += op[1] == '+' ? 1 : -1;
        }
        return ans;
    }
};