/*
 * @Author: LetMeFly
 * @Date: 2026-08-28 13:30:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-28 15:02:36
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool fullBigger(int cnt[26], string& s, int idx, int miniChar) {
        for (; miniChar < 26; miniChar++) {
            if (cnt[miniChar]) {
                cnt[miniChar]--;
                s[idx] = miniChar + 'a';
                return true;
            }
        }
        return false;
    }

    bool full(int cnt[26], string& s, int idx, char c) {
        if (cnt[c - 'a']) {
            s[idx] = c;
            cnt[c - 'a']--;
            return true;
        }
        return false;
    }

    // 依据前半段反转填充后半段
    void full(string& s) {
        for (int i = 0, n = s.size(); i < n / 2; i++) {
            s[n - i - 1] = s[i];
        }
    }

    // 不是前半个字符串的最后一个、或是前半个字符串的最后一个但是fullSame的话double后比target大
    bool canFullSame(int cnt[26], string& s, string& target, int idx) {
        int n = target.size(), half = n / 2;
        if (idx < half - 1) {
            return full(cnt, s, idx, target[idx]);
        }
        if (n % 2 == 0) {
            return false;
        }

        // 现在是奇数长度的字符串 并且 正在填充前半部分的最后一个字符
        if (!full(cnt, s, idx, target[idx])) {  // 直接没一样的字符可填了
            return false;
        }
        // 有一样的字符可以填，但是要看看填上之后整个字符串是否bigger
        for (int i = 0; i <= half; i++) {
            if (s[i] > target[n - i - 1]) {
                return true;
            }
        }
        cnt[target[idx] - 'a']++;  // revert
        return false;
    }
public:
    string lexPalindromicPermutation(string& s, string& target) {
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int oddTimes = 0;
        int oddChar;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                oddTimes++;
                oddChar = i;
            }
            cnt[i] /= 2;
        }
        if (oddTimes > 1) {
            return "";
        }
        if (oddTimes == 1) {
            s[s.size() / 2] = oddChar + 'a';
        }

        bool alreadyBigger = false;
        for (int i = 0, n = target.size() / 2; i < n; i++) {
            if (alreadyBigger) {  // 可以填任意字符
                fullBigger(cnt, s, i, 0);
                continue;
            }
            if (canFullSame(cnt, s, target, i)) {  // 试试填一样的
                continue;
            }
            if (fullBigger(cnt, s, i, target[i] - 'a' + 1)) {  // 有更大的
                alreadyBigger = true;
                continue;
            }
            // 开始回退
            for (; i >= 0; i--) {
                cnt[s[i] - 'a']++;
                if (fullBigger(cnt, s, i, target[i] - 'a' + 1)) {
                    alreadyBigger = true;
                    break;
                }
            }
            if (!alreadyBigger) {  // 走到这里还没有alreadyBigger说明回退失败了
                return "";
            }
        }
        full(s);
        return s > target ? s : "";
    }
};

#ifdef _DEBUG
/*
baba
abba

baab
*/
/*
aab
baa

""
*/
/*
aabb
abaa

abba
*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        Solution sol;
        cout << sol.lexPalindromicPermutation(a, b) << endl;
    }
    return 0;
}
#endif
