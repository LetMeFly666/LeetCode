/*
 * @Author: LetMeFly
 * @Date: 2026-06-17 09:25:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-17 09:48:28
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
abc + **# + k=1
ab
a
aa
 |__ans

k = 1, len = 2, c = #
k = 0, len = 1, c = *
k = 0, len = 2, c = *
k = 0, len = 3
*/

/*
ab***cd + k=1
a
ab
a
.
.
c
cd
 |__ans

k = 1, len = 2, c = d -> return 'd'
*/
typedef long long ll;
class Solution {
public:
    char processStr(string s, ll k) {
        ll len = 0;
        for (char c : s) {
            if ('a' <= c && c <= 'z') {
                len++;
            } else if (c == '*') {
                len = max(len - 1, 0ll);
            } else if (c == '#') {
                len *= 2;
            }  // else { len = len; }  // c is '%'
        }
        if (k >= len) {
            return '.';
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if ('a' <= c && c <= 'z') {
                if (k == len - 1) {
                    return c;
                }
                len--;
            } else if (c == '*') {  // 若是正向操作中存在删没了的情况，则逆向复原时还没到删没了的时候就知道答案了
                len++;
            } else if (c == '#') {
                k = k >= len / 2 ? k - len / 2 : k;
                len /= 2;
            } else {
                k = len - 1 - k;
            }
        }
        return '?';  // 理论上不会走到这里
    }
};

#ifdef _DEBUG
/*
jio#*g
1

i
*/
int main() {
    string s;
    int t;
    while (cin >> s >> t) {
        Solution sol;
        cout << sol.processStr(s, t) << endl;
    }
    return 0;
}
#endif
