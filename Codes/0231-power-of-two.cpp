/*
 * @Author: LetMeFly
 * @Date: 2022-09-08 15:40:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-08 16:08:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 负数特判
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0)
            return false;
        int cnt1 = 0;
        while (n) {
            if (n & 1)
                cnt1++;
            n >>= 1;
        }
        return cnt1 == 1;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    bool isPowerOfTwo(unsigned int n) {
        if (n == INT_MIN)
            return false;
        int cnt1 = 0;
        while (n) {
            if (n & 1)
                cnt1++;
            n >>= 1;
        }
        return cnt1 == 1;
    }
};
#endif  // FirstTry

#ifdef FirstTry
#ifdef _WIN32
/*
a = -5
a = -3
a = -2
a = -1
a = -1
a = -1
a = -1
a = -1
a = -1
a = -1
a = -1
a = -1
...
*/
int main() {
    int a = -5;
    int cnt = 0;
    while (a) {
        dbg(a);
        a >>= 1;

        cnt++;
        if (cnt > 50)
            break;
    }
    return 0;
}
#endif
#else  // FirstTry
// SecondTry
#ifdef _WIN32
int main() {
    unsigned int ui = INT_MIN;
    dbg(ui);
    return 0;
}
#endif
#endif  // FirstTry