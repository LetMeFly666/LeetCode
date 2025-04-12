/*
 * @Author: LetMeFly
 * @Date: 2025-04-12 07:51:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-12 08:50:05
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
            factor[i] = factor[i - 1] * 10;
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
        ll ans = (s.size() - times[0]) * factor[s.size() - 1];
        memset(times, 0, sizeof(times));
        for (char c : s) {
            times[c - '0']++;
        }
        for (int i = 0; i < 10; i++) {
            ans /= factor[times[i]];
        }
        return ans;
    }
public:
    ll countGoodIntegers(int n, int k) {
        initFactor(n);
        this->k = k;
        int half = (n - 1) / 2;
        ll ans = 0;
        for (int start = pow(10, half - 1), end = start * 10; start < end; start++) {
            string prefix = to_string(start), suffix = prefix.substr(0, prefix.size() - n % 2);
            reverse(suffix.begin(), suffix.end());
            string thisNum = prefix + suffix;
            if (!ifVisited(thisNum) && isOk(thisNum)) {
                ans += calc(thisNum);
            }
        }
        return ans;
    }
};