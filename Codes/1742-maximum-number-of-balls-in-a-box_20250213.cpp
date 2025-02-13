/*
 * @Author: LetMeFly
 * @Date: 2025-02-13 16:19:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-13 16:20:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int get(int n) {
        int ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int countBalls(int l, int h) {
        int cnt[46] = {0};
        for (; l <= h; l++) {
            cnt[get(l)]++;
        }
        return *max_element(cnt, cnt + 46);
    }
};