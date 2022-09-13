/*
 * @Author: LetMeFly
 * @Date: 2022-09-13 11:42:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-13 19:20:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // while
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> a(n);
        a[0] = 1;
        int _2 = 0, _3 = 0, _5 = 0;
        int toLoc = 1;
        for (int i = 1; i < n; i++) {
            int ans2 = a[_2] * 2;
            while (ans2 <= a[toLoc - 1]) {
                ans2 = a[++_2] * 2;
            }
            int ans3 = a[_3] * 3;
            while (ans3 <= a[toLoc - 1]) {
                ans3 = a[++_3] * 3;
            }
            int ans5 = a[_5] * 5;
            while (ans5 <= a[toLoc - 1]) {
                ans5 = a[++_5] * 5;
            }
            int m = min(ans2, min(ans3, ans5));
            a[toLoc++] = m;
            if (ans2 == m) {
                _2++;
            }
            else if (ans3 == m) {
                _3++;
            }
            else {
                _5++;
            }
        }
        return a[n - 1];
    }
};
#else  // FirstTry
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> a(n);
        a[0] = 1;
        int _2 = 0, _3 = 0, _5 = 0;
        int toLoc = 1;
        for (int i = 1; i < n; i++) {
            int ans2 = a[_2] * 2;
            int ans3 = a[_3] * 3;
            int ans5 = a[_5] * 5;
            int m = min(ans2, min(ans3, ans5));
            a[toLoc++] = m;
            if (ans2 == m) {
                _2++;
            }
            if (ans3 == m) {
                _3++;
            }
            if (ans5 == m) {
                _5++;
            }
        }
        return a[n - 1];
    }
};
#endif  // FirstTry