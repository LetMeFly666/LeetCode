/*
 * @Author: LetMeFly
 * @Date: 2021-06-08 11:08:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-06-08 11:37:29
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
// // Begin:
// class Solution
// {
// public:
//     int lastStoneWeightII(vector<int> &stones)
//     {
//         int s=accumulate(stones.begin(),stones.end(),0);
//         int n=stones.size(),m=s/2;
//         vector<vector<bool> >dp(n+1, vector<bool>(m+1));
//         dp[0][0]=true;
//         for(int i=0;i<n;i++)
//             for(int j=0;j<=m;j++)
//                 if(j<stones[i])
//                     dp[i+1][j]=dp[i][j];
//                 else
//                     dp[i+1][j]=dp[i][j]|dp[i][j-stones[i]];
//         while(1)
//             if(dp[n][m--])
//                 return s-2*(m+1);
//     }
// };
// // End:

// Begin:
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int s=accumulate(stones.begin(),stones.end(),0);
        int n=stones.size(),m=s/2;
        vector<bool>dp(m+1);
        dp[0]=true;
        for(int i=0;i<n;i++)
            for(int j=m;j>=stones[i];j--)
                dp[j]=dp[j]|dp[j-stones[i]];
        while(1)
            if(dp[m--])
                return s-2*(m+1);
    }
};
/*
执行结果：通过 显示详情 一维背包
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：7.7 MB, 在所有 C++ 提交中击败了97.24%的用户
*/
// End:
int main()
{
    int n;
    vector<int> v;
    while (cin >> n)
        v.push_back(n);
    Solution sol;
    cout << sol.lastStoneWeightII(v) << endl;
    system("pause");
    return 0;
}