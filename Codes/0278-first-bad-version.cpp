/*
 * @Author: LetMeFly
 * @Date: 2022-09-14 14:03:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-14 18:45:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
bool isBadVersion(int n);
#endif

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;  // r = n + 1越界了
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (isBadVersion(mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};