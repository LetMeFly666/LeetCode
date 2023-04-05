/*
 * @Author: LetMeFly
 * @Date: 2023-04-05 22:11:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-05 22:13:09
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
        int n;
        cin >> n;
        int ans = 0;
        int nowSingle = 0, nowGirl = 0, nowBoy = 0;
        while (n--) {
            int t;
            cin >> t;
            if (t == 1) {
                nowSingle++;
            }
            else {
                if (!nowBoy) {
                    nowBoy = 1;
                    nowGirl = nowSingle - 1;
                    nowSingle = 0;
                }
                else {
                    nowGirl += nowSingle;
                    nowSingle = 0;
                }
            }
            ans = max(ans, nowSingle + (nowBoy + 1) / 2 + (nowGirl + 1) / 2);
        }
        cout << ans << endl;
    }
    return 0;
}