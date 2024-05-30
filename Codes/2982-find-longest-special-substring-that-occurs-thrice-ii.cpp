/*
 * @Author: LetMeFly
 * @Date: 2024-05-30 16:20:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-30 17:34:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // AC,95.24%,96.03% 但是add1times复杂了其实
class Solution {
private:
    inline void add1times(int times[], int n) {
        for (int i = 2; i >= 0; i--) {
            if (n > times[i]) {
                times[i] = n;
                break;
            }
        }
        if (times[2] > times[1]) {
            swap(times[2], times[1]);
        }
        if (times[1] > times[0]) {
            swap(times[1], times[0]);
        }
    }

    inline int getTimes(int times[]) {
        return max(
            min(times[0], min(times[1], times[2])),
            max(
                min(times[0] - 1, times[1]),
                times[0] - 2
            )
        );
    }
public:
    int maximumLength(string s) {
        int times[26][3] = {0};
        int from = 0;
        for (int i = 1; i <= s.size(); i++) {
            if (i == s.size() || s[i] != s[i - 1]) {
                add1times(times[s[i - 1] - 'a'], i - from);
                from = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = max(ans, getTimes(times[i]));
        }
        return ans ? ans : -1;
    }
};
#else  // FirstTry
// SecondTry // 相比于FirstTry，仅优化了add1times函数
class Solution {
private:
    inline void add1times(int times[], int n) {
        if (n > times[2]) {
            times[2] = n;
            if (times[2] > times[1]) {
                swap(times[2], times[1]);
                if (times[1] > times[0]) {
                    swap(times[1], times[0]);
                }
            }
        }        
    }

    inline int getTimes(int times[]) {
        return max(
            min(times[0], min(times[1], times[2])),
            max(
                min(times[0] - 1, times[1]),
                times[0] - 2
            )
        );
    }
public:
    int maximumLength(string s) {
        int times[26][3] = {0};
        int from = 0;
        for (int i = 1; i <= s.size(); i++) {
            if (i == s.size() || s[i] != s[i - 1]) {
                add1times(times[s[i - 1] - 'a'], i - from);
                from = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = max(ans, getTimes(times[i]));
        }
        return ans ? ans : -1;
    }
};
#endif  // FirstTry