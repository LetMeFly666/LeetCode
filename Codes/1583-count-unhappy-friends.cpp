/*
 * @Author: LetMeFly
 * @Date: 2021-08-14 17:24:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-14 17:25:38
 */

// copy from official editorial
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
    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs)
    {
        vector<vector<int>> order(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                order[i][preferences[i][j]] = j;
            }
        }
        vector<int> match(n);
        for (const auto &pr : pairs)
        {
            match[pr[0]] = pr[1];
            match[pr[1]] = pr[0];
        }

        int unhappyCount = 0;
        for (int x = 0; x < n; ++x)
        {
            int y = match[x];
            int index = order[x][y];
            for (int i = 0; i < index; ++i)
            {
                int u = preferences[x][i];
                int v = match[u];
                if (order[u][x] < order[u][v])
                {
                    ++unhappyCount;
                    break;
                }
            }
        }
        return unhappyCount;
    }
};