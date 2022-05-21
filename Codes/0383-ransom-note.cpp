/*
 * @Author: LetMeFly
 * @Date: 2021-12-04 20:19:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-04 20:21:29
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int bin[26] = {0};
        for (char &c : magazine) {
            bin[c - 'a']++;
        }
        for (char &c : ransomNote) {
            bin[c - 'a']--;
            if (bin[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};