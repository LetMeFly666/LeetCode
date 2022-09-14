/*
 * @Author: LetMeFly
 * @Date: 2022-09-14 13:43:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-14 13:50:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 方法一，时间O(n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n - i) {
                return n - i;
            }
        }
        return 0;
    }
};
#else  // FirstTry
// SecondTry  // 二分
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (citations[mid] >= n - mid) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return n - l;
    }
};
#endif  // FirstTry