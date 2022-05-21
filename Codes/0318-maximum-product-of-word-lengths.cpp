/*
 * @Author: LetMeFly
 * @Date: 2021-11-17 18:25:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-17 18:30:18
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
struct Character26 {
    bool have[26];
};
class Solution {
private:
    bool ok(Character26& a, Character26& b) {
        for (int i = 0; i < 26; i++) {
            if (a.have[i] && b.have[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int maxProduct(vector<string>& words) {
        vector<Character26> v(words.size());
        for (int i = 0; i < words.size(); i++) {
            for (char &c : words[i]) {
                v[i].have[c - 'a'] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (ok(v[i], v[j])) {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};