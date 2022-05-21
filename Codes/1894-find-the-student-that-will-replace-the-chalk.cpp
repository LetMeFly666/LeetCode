/*
 * @Author: LetMeFly
 * @Date: 2021-09-10 11:12:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-10 11:16:25
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
    int chalkReplacer(vector<int> &chalk, int k)
    {
        ll sum = 0;
        for (int &i : chalk)
        {
            sum += i;
        }
        k %= sum;
        for(int i = 0; i < chalk.size(); i++)
        {
            k -= chalk[i];
            if (k < 0) return i;
        }
        assert(false);
        return -1;
    }
};