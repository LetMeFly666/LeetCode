/*
 * @Author: LetMeFly
 * @Date: 2026-03-31 21:55:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-31 23:21:23
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif
/*
1 3 5 7不一样
idx[7]++

str1: F
str2: bxxx
ans:  aaaa
只要前面有不一样的，后面则能修改的全a就好
当然后面任意都行，如果后面的F需要修改某个a为其他完全ok

str1: F
str2: abxx
ans1: aaaa  第一个字符还a，但后面至少有个不一样的
ans2: baaa  第一个字符就不一样，后面全a就好（当然也能再改）
如果能构造ans1，一定比ans2更优，因为ans1后面字符的不同于str2会导致后面F更容易

str1: F
str2: aabx
ans:  aaaa

str1: F
str2: aaaa
ans:  aaab
*/
class Solution {
private:
    int n, m;
    vector<bool> can_change;

    bool fillT(string& ans, int idx, const string& s) {
        for (int i = 0; i < m; i++) {
            if (ans[i + idx] == '-') {
                ans[i + idx] = s[i];
                can_change[i + idx] = false;
            } else {
                if (ans[i + idx] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool fillF(string& ans, int idx, const string& s) {
        if (all_cannot_change_and_all_same(ans, idx, s)) {
            return false;
        }

        // 以下逻辑一定能设置成功ans.sub(idx)

        if (can_changed_place_are_all_a(ans, idx, s)) {
            // 要改且能改位置全是a，挑最后一个能改位置改为b
            change_last2b(ans, idx, s);
        } else {
            // 可设置为全a，这样就满足F
            set_all_a(ans, idx, s);
        }
        return true;
    }

    bool all_cannot_change_and_all_same(string& ans, int idx, const string& s) {
        for (int i = 0; i < m; i++) {
            if (can_change[i + idx] || ans[i + idx] != s[i]) {
                return false;
            }
        }
        return true;
    }

    // 可以修改的位置对应str2全部是a
    bool can_changed_place_are_all_a(string& ans, int idx, const string& s) {
        for (int i = 0; i < m; i++) {
            if (can_change[i + idx] && s[i] != 'a') {
                return false;
            } else if (!can_change[i + idx] && ans[i + idx] != s[i]) {
                return false;
            }
        }
        return true;
    }

    void change_last2b(string& ans, int idx, const string& s) {
        bool is_last = true;
        for (int i = m - 1; i >= 0; i--) {
            if (can_change[i + idx]) {
                if (is_last) {
                    ans[i + idx] = 'b';
                    is_last = false;
                    can_change[i + idx] = false;
                } else {
                    ans[i + idx] = 'a';
                }
            }
        }
    }

    void set_all_a(string& ans, int idx, const string& s) {
        for (int i = 0; i < m; i++) {
            if (can_change[i + idx]) {
                ans[i + idx] = 'a';
            }
        }
    }
public:
    string generateString(const string& str1, const string& str2) {
        n = str1.size();
        m = str2.size();
        string ans(n + m - 1, '-');
        can_change = move(vector<bool>(n + m - 1, true));
        
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == 'T') {
                if (!fillT(ans, i, str2)) {
                    return "";
                }
            }
        }

        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == 'F') {
                if (!fillF(ans, i, str2)) {
                    return "";
                }
            }
        }

        return ans;
    }
};

#ifdef _DEBUG
/*
TFTF
ab

ababa
*/
/*
FT
aghbdfhf

aaghbdfhf
*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        Solution sol;
        cout << sol.generateString(a, b) << endl;
    }
    return 0;
}
#endif
