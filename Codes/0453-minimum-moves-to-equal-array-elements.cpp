/*
 * @Author: LetMeFly
 * @Date: 2021-10-20 22:01:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-20 22:02:49
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
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int m = nums[0];
        for (int &t: nums) {
            m = min(m, t);
        }
        for (int &t: nums) {
            ans += t - m;
        }
        return ans;
    }
};