/*
 * @Author: LetMeFly
 * @Date: 2021-11-10 09:10:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-10 09:15:50
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
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        sort(timeSeries.begin(), timeSeries.end());
        int ans = 0;
        int lastTo = -1;
        for (int attackTime : timeSeries) {
            int thisTo = attackTime + duration - 1;
            ans += thisTo - max(lastTo, attackTime - 1);
            lastTo = thisTo;
        }
        return ans;
    }
};