/*
 * @Author: LetMeFly
 * @Date: 2021-07-23 22:01:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-23 22:03:54
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

//----------------------
class Solution
{
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        bool sf[55] = {0};
        for (int i = 0; i < ranges.size(); i++)
        {
            for (int j = ranges[i][0]; j <= ranges[i][1]; j++)
            {
                sf[j] = true;
            }
        }
        for (int i = left; i <= right; i++)
        {
            if (!sf[i])
                return false;
        }
        return true;
    }
};
//----------------------
