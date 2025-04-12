/*
 * @Author: LetMeFly
 * @Date: 2025-04-12 07:51:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-12 09:25:01
 * @Description: AC,21.21%,93.94%
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
    unordered_set<string> visited;
    vector<int> factor;
    int times[10];

    void initFactor(int n) {
        factor.resize(n + 1);
        factor[0] = 1;
        for (int i = 1; i <= n; i++) {
            factor[i] = factor[i - 1] * i;
        }
    }

    bool ifVisited(string s) {
        sort(s.begin(), s.end());
        if (visited.count(s)) {
            return true;
        }
        visited.insert(s);
        return false;
    }
    
    bool isOk(string& s) {
        ll val = stoll(s);
        // printf("%s: %d\n", s.c_str(), val % k == 0);  // *****
        return val % k == 0;
    };

    ll calc(string& s) {
        memset(times, 0, sizeof(times));
        for (char c : s) {
            times[c - '0']++;
        }
        ll ans = (s.size() - times[0]) * factor[s.size() - 1];
        for (int i = 0; i < 10; i++) {
            ans /= factor[times[i]];
        }
        return ans;
    }
public:
    ll countGoodIntegers(int n, int k) {
        initFactor(n);
        this->k = k;
        ll ans = 0;
        for (int start = pow(10, (n - 1) / 2), end = start * 10; start < end; start++) {
            string prefix = to_string(start), suffix = prefix.substr(0, prefix.size() - n % 2);
            reverse(suffix.begin(), suffix.end());
            string thisNum = prefix + suffix;
            if (isOk(thisNum) && !ifVisited(thisNum)) {
                printf("ans: %lld, calc(%s): %lld, ans = ans + calc(%s) = %lld\n", ans, thisNum.c_str(), calc(thisNum), thisNum.c_str(), ans + calc(thisNum));  // ****
                ans += calc(thisNum);
            }
        }
        return ans;
    }
};