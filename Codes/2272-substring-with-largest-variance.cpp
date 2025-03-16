/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 10:43:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 11:03:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // WA - 例如baa，一个变量会导致不选b，而只有aa虽然cnt比较大但不一定最优
class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            char a = i + 'a';
            for (int j = 0; j < 26; j++) {
                char b = j + 'a';
                int cnt = 0;
                bool hasB = false;
                for (char c : s) {
                    if (c == a) {
                        cnt++;
                    } else if (c == b) {
                        // cnt = max(cnt - 1, 0);
                        if (cnt - 1 >= 0) {
                            cnt--;
                            hasB = true;
                        } else {
                            cnt = 0;
                            hasB = false;
                        }
                    }
                    if (hasB) {
                        ans = max(ans, cnt);
                    }
                }
                // printf("a = %c, b = %c, ans = %d\n", a, b, ans);
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            char a = i + 'a';
            for (int j = 0; j < 26; j++) {
                char b = j + 'a';
                int mayNoB = 0, hasB = -10000000;
                for (char c : s) {
                    if (c == a) {
                        mayNoB = max(mayNoB + 1, 1);
                        hasB++;
                    } else if (c == b) {
                        mayNoB = max(mayNoB - 1, -1);
                        hasB = mayNoB;
                    }
                    ans = max(ans, hasB);
                }
            }
        }
        return ans;
    }
};
#endif  // FirstTry