/*
 * @Author: LetMeFly
 * @Date: 2022-10-25 11:00:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-25 11:07:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


#ifdef FirstTry
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int mask = 1 << i;
            ans += ((x & mask) != (y & mask));
        }
        return ans;
    }
};
#else  // FirstTry
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            ans += (((x >> i) & 1) != ((y >> i) & 1));
        }
        return ans;
    }
};
#endif  // FirstTry