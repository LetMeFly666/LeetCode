/*
 * @Author: LetMeFly
 * @Date: 2021-08-24 13:20:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-24 13:26:25
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
#define INT_MAX 10000000
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int>dp(n,INT_MAX);
        dp[src]=0;
        int ans=INT_MAX;
        for(int t=0;t<=k;t++)
        {
            vector<int>temp(n,INT_MAX);
            for(auto && flight: flights)
            {
                temp[flight[1]]=min(temp[flight[1]],dp[flight[0]]+flight[2]);
            }
            dp=move(temp);
            ans=min(ans,dp[dst]);
        }
        return ans==INT_MAX?-1:ans;
    }
};