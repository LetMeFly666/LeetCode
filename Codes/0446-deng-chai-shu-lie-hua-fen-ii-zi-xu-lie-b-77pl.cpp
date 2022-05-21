/*
 * @Author: LetMeFly
 * @Date: 2021-08-11 13:02:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-11 13:05:23
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
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int ans=0;
        int n=nums.size();
        unordered_map<ll,int>dp[n];
        fi(i,1,n)
            fi(j,0,i)
            {
                ll d=1ll*nums[i]-nums[j];
                unordered_map<ll,int>::iterator it=dp[j].find(d);
                int cnt=it==dp[j].end()?0:it->second;
                ans+=cnt,dp[i][d]+=cnt+1;
            }
        return ans;
    }
};