/*
 * @Author: LetMeFly
 * @Date: 2025-09-06 10:23:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-06 10:39:29
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

/*
0 1 1 2
   ⬇️
0 1 2 1
*/
/*
0 1 3 4
0 1 - 后面无所谓了
*/
int main() {
    int n;
    cin >> n;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    vector<ll> sorted;
    vector<bool> used(n);
    for (ll finding = 0, i = 0; i < n; i++) {
        if (v[i] == finding) {
            finding++;
            used[i] = true;
            sorted.push_back(v[i]);
            while (i + 1 < n && v[i + 1] == v[i]) {
                i++;
                ans += finding;
            }
        }
        ans += finding;
        // printf("finding = %lld, i = %lld, ans = %lld\n", finding, i, ans);  //****
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            sorted.push_back(v[i]);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        if (i) {
            putchar(' ');
        }
        cout << sorted[i];
    }
    return 0;
}

/*
3
1 0 1
*/