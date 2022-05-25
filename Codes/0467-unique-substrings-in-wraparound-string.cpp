/*
 * @Author: LetMeFly
 * @Date: 2022-05-25 08:34:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-25 09:17:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 重复计数了。比如cac，c记了两次
#define getLR(l, r) ((1 << (r - l)) - 1)
class Solution {
public:
    int findSubstringInWraproundString(string& p) {
        int ans = 0;
        int lastLoc = 0;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] - 'a' != (p[i - 1] - 'a' + 1) % 26) {  // [lastLoc, i)
                ans += getLR(lastLoc, i);
                lastLoc = i;
            }
        }
        ans += getLR(lastLoc, p.size());
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // set超时
class Solution {
public:
    int findSubstringInWraproundString(string& p) {
        set<string> se;
        function<void(int, int)> cal = [&se, &p](int l, int r) {
            for (int length = 1; length <= p.size(); length++) {
                for (int startLoc = l; startLoc + length - 1 < r; startLoc++) {
                    se.insert(p.substr(startLoc, length));
                }
            }
        };
        int lastLoc = 0;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] - 'a' != (p[i - 1] - 'a' + 1) % 26) {  // [lastLoc, i)
                cal(lastLoc, i);
                lastLoc = i;
            }
        }
        cal(lastLoc, p.size());
        return se.size();
    }
};
#else  // SecondTry
// ThirdTry
class Solution {
public:
    int findSubstringInWraproundString(string& p) {
        int endBy[26] = {0};
        int length = 0;
        for (int i = 0; i < p.size(); i++) {
            if (i && (p[i] - 'a') == (p[i - 1] - 'a' + 1) % 26) {
                length++;
            }
            else {
                length = 1;
            }
            endBy[p[i] - 'a'] = max(endBy[p[i] - 'a'], length);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
            ans += endBy[i];
        return ans;
    }
};
#endif  // SecondTry
#endif  // FirstTry

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.findSubstringInWraproundString(s) << endl;
    }
    return 0;
}
#endif