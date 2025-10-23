/*
 * @Author: LetMeFly
 * @Date: 2025-10-22 19:37:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-22 19:42:07
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
5
11101

2
*/
/*
10
1100010101

8
*/
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char first = s[0];
    int canDestroy = 0;
    int destroyed = 0;
    int cntFirst = 0;
    for (char c : s) {
        if (c == first) {
            cntFirst++;
            if (canDestroy) {
                canDestroy--;
                destroyed++;
            }
        } else {
            canDestroy++;
        }
    }
    cout << n - (cntFirst - destroyed) << endl;
    return 0;
}