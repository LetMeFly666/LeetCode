/*
 * @Author: LetMeFly
 * @Date: 2025-10-25 20:18:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-25 20:42:11
 */
#include <bits/stdc++.h>
using namespace std;
/*
1  2  3
      5
*/
/*
5  12 13  7 8
1. 5 12 13
2. 5 7 8 
*/
/*
SAMPLE 1
5
10 20 30 15 25
3
10 15 30

2
*/
/*
SAMPLE 2
7
5 10 15 8 20 25 18
4
5 8 20 18

2
*/
/*
5
5  12 13  7 8
0
*/
vector<int> rollback(vector<pair<int, int>>& dp, vector<int>& a, int start) {
    vector<int> ans;
   do {
        ans.push_back(a[start]);
        start = dp[start].second;
    } while (start != -1);
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<vector<int>> getAllMaxUp(vector<int>& a) {
    vector<pair<int, int>> dp(a.size(), {0, -1});  // [<length, last>, ...
    int maxLength = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j].first >= dp[i].first) {
                dp[i] = {dp[j].first + 1, j};
                maxLength = max(maxLength, dp[i].first);
            }
        }
    }
    vector<vector<int>> ans;
    for (int i = 0; i < a.size(); i++) {
        if (dp[i].first == maxLength) {
            ans.push_back(rollback(dp, a, i));
        }
    }
    return ans;
}

void dbgVectorInt(vector<int>& a) {
    for (int t : a) {
        cout << t << ' ';
    }
    puts("");
}

void dbgVectorVectorInt(vector<vector<int>>& a) {
    for (vector<int>& v : a) {
        dbgVectorInt(v);
    }
}

/*
10 20 30
10 15 30
*/
// 序列a包含集合b
int maxSame(vector<int>& a, unordered_set<int>& b) {
    int ans = 0;
    for (int t : a) {
        ans += b.count(t);
    }
    return ans;
}

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
    vector<vector<int>> ups = getAllMaxUp(a);
    // dbgVectorVectorInt(ups);
    unordered_set<int> se(b.begin(), b.end());
    int ans = 0;
    for (vector<int>& a : ups) {
        ans = max(ans, maxSame(a, se));
    }
    cout << ans << endl;
    return 0;
}