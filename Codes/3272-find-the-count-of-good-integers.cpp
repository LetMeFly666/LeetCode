/*
 * @Author: LetMeFly
 * @Date: 2025-04-12 07:51:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-12 08:31:33
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
1 -> 1-9
2 -> 1-9
3 -> 10->99
4 -> 10->99
5 -> 100->999
6 -> 100->999

n -> [10^((n-1)/2-1), 10^((n-1)/2)-1)
*/
typedef long long ll;

class Solution {
private:
    int k;

    bool isOk(string s) {
        ll val = stoll(s);
        // printf("%s: %d\n", s.c_str(), val % k == 0);  // *****
        return val % k == 0;
    };
public:
    ll countGoodIntegers(int n, int k) {
        this->k = k;
        if (n == 1) {
            return 9 / k;
        }
        int half = n / 2;
        ll ans = 0;
        for (int start = pow(10, half - 1), end = start * 10; start < end; start++) {
            string prefix = to_string(start), suffix = prefix.substr(0, prefix.size() - n % 2);
            reverse(suffix.begin(), suffix.end());
            ans += isOk(prefix + suffix);
        }
        return ans;
    }
};