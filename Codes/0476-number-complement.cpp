/*
 * @Author: LetMeFly
 * @Date: 2021-10-18 01:53:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-18 01:55:24
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
    int findComplement(int num) {
        string s;
        while(num) {
            s = char((num & 1) + '0') + s;
            num >>= 1;
        }
        int ans = 0;
        for (char &c: s) {
            ans *= 2;
            if (c == '0') { // !c = 1
                ans++;
            }
        }
        return ans;
    }
};