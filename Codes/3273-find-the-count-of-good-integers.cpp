/*
 * @Author: LetMeFly
 * @Date: 2025-04-12 07:51:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-12 08:00:58
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
private:
    bool isOk(string s, int k) {
        ll val = stoll(s);
        printf("%s: %d\n", s.c_str(), val % k == 0);  // *****
        return val % k == 0;
    };
public:
    ll countGoodIntegers(int n, int k) {
        int half = n / 2;
        ll ans = 0;
        for (int start = pow(10, half), end = start * 10; start < end; start++) {
            string prefix = to_string(start), suffix = prefix;
            reverse(suffix.begin(), suffix.end());
            if (n % 2) {
                for (int i = 0; i < 10; i++) {
                    ans += isOk(prefix + char('0' + i) + suffix, k);
                }
            } else {
                ans += isOk(prefix + suffix, k);
            }
        }
        return ans;
    }
};