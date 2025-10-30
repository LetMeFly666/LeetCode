/*
 * @Author: LetMeFly
 * @Date: 2025-10-25 19:44:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-25 19:46:02
 */
#include <bits/stdc++.h>
using namespace std;

char changeFrom[15][4];
char changeTo[15];
int n, m;
int ans = 0;
// 原来只能替换字符串首
/*
5 5
acd b
acf b
bcc c
bdd e
ccc e
e

3
*/

/*
9 4
abc d
def g
ghi j
jkl m
m

1
*/
void change(string& from) {
    int l = from.size();
    if (l == n) {
        // cout << from << endl;
        ans++;
        return;
    }
    for (int j = 0; j < m; j++) {
        if (from[0] == changeTo[j]) {
            string to = changeFrom[j] + from.substr(1, l - 1);
            change(to);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> changeFrom[i] >> changeTo[i];
        // cout << changeFrom[i] << ' ' << changeTo[i] << endl;
    }
    string original;
    cin >> original;
    change(original);
    cout << ans << endl;
    return 0;
}