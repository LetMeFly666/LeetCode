/*
 * @Author: LetMeFly
 * @Date: 2021-11-20 18:46:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-20 18:47:55
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
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> ma;
        for (int &t : nums) ma[t]++;
        int ans = 0;
        for (pair<int, int> pii : ma) {
            if (ma[pii.first - 1]) {
                ans = max(ans, ma[pii.first - 1] + pii.second);
            }
        }
        return ans;
    }
};