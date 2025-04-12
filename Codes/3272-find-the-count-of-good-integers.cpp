/*
 * @Author: LetMeFly
 * @Date: 2025-04-12 07:51:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-12 08:19:56
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
1 -> ''
2 -> 1-9
3 -> 1-9
4 -> 10->99
5 -> 10->99
6 -> 100->999

n -> [10^(n/2-1), 10^(n/2)-1)
*/
typedef long long ll;

class Solution {
private:
    bool isOk(string s, int k) {
        ll val = stoll(s);
        // printf("%s: %d\n", s.c_str(), val % k == 0);  // *****
        return val % k == 0;
    };
public:
    ll countGoodIntegers(int n, int k) {
        if (n == 1) {
            return 9 / k;
        }
        int half = n / 2;
        ll ans = 0;
        for (int start = pow(10, half - 1), end = start * 10; start < end; start++) {
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