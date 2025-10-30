/*
 * @Author: LetMeFly
 * @Date: 2025-10-22 18:56:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-22 19:27:43
 */
// 发卷发了1min多
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
2
36 15

114
*/
int main() {
    int N;
    cin >> N;
    int bit[11] = {0};
    int num[10] = {0};
    int cnt = 0;
    while (N--) {
        int t;
        cin >> t;
        string s = to_string(t);
        for (int i = 0; i < s.size(); i++) {
            bit[i]++;
            num[s[i] - '0']++;
            cnt++;
        }
    }
    ll ans = 0;
    ll locBit = 0, k = 1, locNum = 0;
    while (cnt--) {
        while (num[locNum] == 0) {
            locNum++;
        }
        while (bit[locBit] == 0) {
            locBit++;
            k *= 10;
        }
        num[locNum]--;
        bit[locBit]--;
        ans += k * locNum;
    }
    cout << ans << endl;
    return 0;
}