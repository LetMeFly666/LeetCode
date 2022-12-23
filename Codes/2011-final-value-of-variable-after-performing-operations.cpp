/*
 * @Author: LetMeFly
 * @Date: 2022-12-23 19:17:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-23 19:18:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (auto& s : operations) {
            if (s[1] == '+')
                ans++;
            else
                ans--;
        }
        return ans;
    }
};