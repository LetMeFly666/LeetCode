/*
 * @Author: LetMeFly
 * @Date: 2021-07-30 09:21:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-30 09:31:21
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
    int titleToNumber(string columnTitle)
    {
        int ans = 0;
        int l = columnTitle.size();
        for (int i = 0; i < l; i++)
        {
            ans *= 26;
            ans += columnTitle[i] - 'A' + 1;
        }
        return ans;
    }
};

int main()
{
    string s;
    while (cin >> s)
    {
        Solution sol;
        cout << sol.titleToNumber(s) << endl;
    }
    system("pause");
    return 0;
}