/*
 * @Author: LetMeFly
 * @Date: 2025-01-09 11:03:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-09 12:39:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
private:
    bool ok(int* cnt1, int* cnt2) {
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] < cnt2[i]) {
                return false;
            }
        }
        return true;
    }
public:
    ll validSubstringCount(string& word1, string& word2) {
        int cnt1[26] = {0}, cnt2[26] = {0};
        for (char c : word2) {
            cnt2[c - 'a']++;
        }
        ll ans = 0;
        for (int l = 0, r = 0; l < word1.size(); l++, r = max(r, l)) {
            if (l) {
                cnt1[word1[l - 1] - 'a']--;
            }
            while (!ok(cnt1, cnt2)) {
                if (r == word1.size()) {
                    return ans;
                }
                cnt1[word1[r++] - 'a']++;
            }
            ans += word1.size() - r + 1;
        }
        return ans;
    }
};

#ifdef _WIN32
/*
bcca
abc

1
*/
/*
abcabc
abc

10
*/
int main() {
    Solution sol;
    string a, b;
    while (cin >> a >> b) {
        cout << sol.validSubstringCount(a, b) << endl;
    }
    return 0;
}
#endif