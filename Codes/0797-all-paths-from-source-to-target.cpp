/*
 * @Author: LetMeFly
 * @Date: 2021-08-25 12:01:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-25 12:08:53
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
void dfs(int start, int to, vi&now, vvi&ans, vvi&graph)
{
    now.push_back(start);
    if(start == to)
    {
        ans.push_back(now);
    }
    else
    {
        for(int &could:graph[start])
        {
            dfs(could,to,now,ans,graph);
            now.pop_back();
        }
    }
}
class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vvi ans;
        int n=graph.size();
        vi now;
        dfs(0,n-1,now,ans,graph);
        return ans;
    }
};