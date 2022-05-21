/*
 * @Author: LetMeFly
 * @Date: 2021-11-24 21:05:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-24 21:14:05
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
/*
    zero
    one
    two 
    three
    four
    five
    six
    seven
    eight
    nine
*/
// class Solution {
// private:
//     const string _0to9[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

// public:
//     string originalDigits(string s) {
//         int bin[26] = {0};
//         for (char c : s) {
//             bin[c - 'a']++;
//         }
//         string ans;
//         for (int i = 0; i < 10; i++) {
//             int m = 1000000;
//             for (char c : _0to9[i]) {
//                 m = min(m, bin[c - 'a']);
//             }
//             for (char c : _0to9[i]) {
//                 bin[c - 'a'] -= m;
//             }
//             while (m--) ans += (i + '0');
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> c;
        for (char ch: s) {
            ++c[ch];
        }

        vector<int> cnt(10);
        cnt[0] = c['z'];
        cnt[2] = c['w'];
        cnt[4] = c['u'];
        cnt[6] = c['x'];
        cnt[8] = c['g'];

        cnt[3] = c['h'] - cnt[8];
        cnt[5] = c['f'] - cnt[4];
        cnt[7] = c['s'] - cnt[6];

        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];

        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += char(i + '0');
            }
        }
        return ans;
    }
};