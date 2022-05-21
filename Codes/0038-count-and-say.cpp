/*
 * @Author: LetMeFly
 * @Date: 2021-10-15 17:31:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-15 17:33:59
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
string newDescription(string &s) {
    string ans;
    int l = 0, n = s.size();
    while (l < n) {
        int r = l + 1;
        for (; r < n; r++) {
            if (s[r] != s[r - 1]) {
                break;
            }
        }
        ans += to_string(r - l);
        ans += s[l];
        l = r;
    }
    return ans;
}
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; i++) {
            ans = newDescription(ans);
        }
        return ans;
    }
};

int main() {
    int n;
    while(cin >> n) {
        Solution sol;
        cout << sol.countAndSay(n) << endl;
    }
    return 0;
}