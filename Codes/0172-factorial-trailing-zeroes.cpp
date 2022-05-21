/*
 * @Author: LetMeFly
 * @Date: 2022-03-25 08:28:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-25 08:33:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef First_Try
// 其实这样的话直接只记cnt5就行了（cnt5<=cnt2）
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt2 = 0, cnt5 = 0;
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) {
                int temp = i;
                while (temp % 2 == 0) {
                    cnt2++;
                    temp /= 2;
                }
            }
            if (i % 5 == 0) {
                int temp = i;
                while (temp % 5 == 0) {
                    cnt5++;
                    temp /= 5;
                }
            }
        }
        return min(cnt2, cnt5);
    }
};
#else
// LeetCode题解：数学方法
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
#endif