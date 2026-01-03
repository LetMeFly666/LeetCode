/*
 * @Author: LetMeFly
 * @Date: 2026-01-03 21:06:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-03 21:29:33
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    const long long MOD = 1e9 + 7;
    static vector<int> okList;
    static unordered_map<int, bool> okCache;

    inline int getFirst(int n) {
        return n % 3;
    }

    inline int getSecond(int n) {
        return n / 3 % 3;
    }

    inline int getThird(int n) {
        return n / 9;
    }

    bool isOk(int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        int key = a * 27 + b;
        if (okCache.count(key)) {
            return okCache[key];
        }
        
        int a1 = getFirst(a);
        int a2 = getSecond(a);
        int a3 = getThird(a);
        int b1 = getFirst(b);
        int b2 = getSecond(b);
        int b3 = getThird(b);
        
        return okCache[key] = a1 != b1 && a2 != b2 && a3 != b3;
    }

    void init() {
        static bool first = true;
        if (!first) {
            return;
        }
        first = false;
        for (int i = 0; i < 27; i++) {
            int first = getFirst(i);
            int second = getSecond(i);
            int third = getThird(i);
            if (first != second && second != third) {
                okList.push_back(i);
            }
        }
    }
public:
    int numOfWays(int n) {
        init();
        long long a[27] = {0};
        long long b[27] = {0};
        for (int t : okList) {
            a[t] = 1;
        }

        while (--n) {
            for (int first : okList) {
                for (int second : okList) {
                    if (isOk(first, second)) {
                        b[second] = (b[second] + a[first]) % MOD;
                    }
                }
            }
            swap(a, b);
            memset(b, 0, sizeof(b));
        }
        return accumulate(a, a + 27, 0ll) % MOD;
    }
};

vector<int> Solution::okList;
unordered_map<int, bool> Solution::okCache;