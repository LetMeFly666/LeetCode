/*
 * @Author: LetMeFly
 * @Date: 2025-12-24 13:30:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-24 13:32:26
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<>());
        int cnt = 0;
        for (int t : apple) {
            cnt += t;
        }
        int ans = 0;
        for (int t : capacity) {
            cnt -= t;
            ans++;
            if (cnt <= 0) {
                return ans;
            }
        }
        return -1;  // Fake Return
    }
};