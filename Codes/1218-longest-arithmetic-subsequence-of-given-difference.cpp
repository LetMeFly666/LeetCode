/*
 * @Author: LetMeFly
 * @Date: 2021-11-05 13:22:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-05 13:23:40
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        unordered_map<int, int> ma;
        for (int &v : arr) {
            ma[v] = ma[v - difference] + 1;
            ans = max(ans, ma[v]);
        }
        return ans;
    }
};