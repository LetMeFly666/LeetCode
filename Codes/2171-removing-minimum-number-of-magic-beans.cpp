/*
 * @Author: LetMeFly
 * @Date: 2024-01-18 19:20:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-18 19:28:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long left = 0, right = accumulate(beans.begin(), beans.end(), 0);
        long long ans = right;
        for (int i = 0; i < beans.size(); i++) {
            left += beans[i];
            right -= beans[i];
            ans = min(ans, left + right - beans[i] * ((long long)beans.size() - i - 1));
        }
        return ans;
    }
};