/*
 * @Author: LetMeFly
 * @Date: 2023-12-09 20:31:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-09 20:34:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isok(int n) {
        int cnt[10] = {0};
        while (n) {
            cnt[n % 10]++;
            n /= 10;
        }
        for (int i = 0; i <= 9; i++) {
            if (cnt[i] && cnt[i] != i) {
                return false;
            }
        }
        return true;
    }

public:
    int nextBeautifulNumber(int n) {
        while (!isok(++n));
        return n;
    }
};