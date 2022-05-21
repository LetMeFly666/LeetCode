/*
 * @Author: LetMeFly
 * @Date: 2021-08-28 08:38:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-28 08:38:14
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        for(int i=1;i<nums.size();i++)
            nums[i]+=nums[i-1];
        return nums;
    }
};