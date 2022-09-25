/*
 * @Author: LetMeFly
 * @Date: 2022-09-25 19:59:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-25 20:02:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isGoodNum(int n) {
        bool haveDifferent = false;
        while (n) {
            int t = n % 10;
            n /= 10;
            if (t == 2 || t == 5 || t == 6 || t == 9) {
                haveDifferent = true;
            }
            else if (t == 0 || t == 1 || t == 8) {
                continue;
            }
            else {
                return false;
            }
        }
        return haveDifferent;
    }
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += isGoodNum(i);
        }
        return ans;
    }
};