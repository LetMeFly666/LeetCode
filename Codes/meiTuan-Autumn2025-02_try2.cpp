/*
 * @Author: LetMeFly
 * @Date: 2025-09-06 10:23:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-06 10:53:00
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

/*
给定一个长度为n的数组v，可以重新排列数组。
重新排列后，定义一个长度同样为n的数组b，b[i] = mex(v[0], v[1], ..., v[i])
其中mex(v)表示v中没有出现过的最小非负整数。
你需要最大化b中的元素之和，返回这个最大值，以及一个可能的a的重排方案。

数据范围：1<=n<=10^5
0<=v[i]<=10^9
*/

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
    vector<ll> sorted;
    vector<bool> used(n);
    for (ll finding = 0, i = 0; i < n; i++) {
        if (v[i] == finding) {
            finding++;
            used[i] = true;
            sorted.push_back(v[i]);
            while (i + 1 < n && v[i + 1] == v[i]) {
                i++;
            }
        } else {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            sorted.push_back(v[i]);
        }
    }

    ll ans = 0;
    for (ll mini = 0, i = 0; i < n; i++) {
        if (sorted[i] == mini) {
            mini++;
        }
        ans += mini;
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