/*
 * @Author: LetMeFly
 * @Date: 2025-10-25 19:52:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-25 20:10:00
 */
#include <bits/stdc++.h>
using namespace std;

inline int getNextIdx(vector<int>& a, int start, int finding) {
    while (start < a.size()) {
        if (a[start] == finding) {
            return start;
        }
        start++;
    }
    return 1000000;
}

/*
1  2  3
      5


*/
/*
5
10 20 30 15 25
3
10 15 30

2
*/
/*
7
5 10 15 8 20 25 18
4
5 8 20 18

2
*/
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<pair<int, int>> dp(m + 1);  // [<length, idx>, ...
    dp[0] = {0, -1};
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int l = -1, idx = -1, choose = -1;
        for (int j = 0; j <= i; j++) {
            if (dp[j].first > l || dp[j].first == l && dp[j].second < idx) {
                l = dp[j].first, idx = dp[j].second, choose = j;
            }
        }
        int nextIdx = getNextIdx(a, idx + 1, b[i]);
        if (nextIdx == 1000000) {
            dp[i] = {0, -1};
        } else {
            cout << b[choose] << " -> " << b[i] << "; <" << dp[choose].first << ", " << dp[choose].second << ">" << endl;
            dp[i] = {l + 1, nextIdx};
            ans = max(ans, l + 1);
        }
    }
    cout << ans << endl;
    return 0;
}