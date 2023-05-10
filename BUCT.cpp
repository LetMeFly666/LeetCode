/*
 * @Author: LetMeFly
 * @Date: 2023-05-10 16:26:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-10 16:43:47
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int locMul = s.find('*');
        ll originalVal = stoll(s.substr(0, locMul)) * stoll(s.substr(locMul + 1, s.size() - locMul - 1));
        string pureNum = s.substr(0, locMul) + s.substr(locMul + 1, s.size() - locMul - 1);
        for (int loc = 1; loc < pureNum.size(); loc++) {  // 将乘号置于哪个下标之前
            if (loc == locMul) {
                continue;
            }
            if (originalVal == stoll(pureNum.substr(0, loc)) * stoll(pureNum.substr(loc, pureNum.size() - loc))) {
                puts("Yes");
                goto loop;
            }
        }
        puts("No");
        loop:;
    }
    return 0;
}