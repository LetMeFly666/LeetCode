/*
 * @Author: LetMeFly
 * @Date: 2021-09-06 12:43:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-06 12:45:07
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
    int search(vector<int>& nums, int target) {
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target) return -1;
        return it - nums.begin();
    }
};