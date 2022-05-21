/*
 * @Author: LetMeFly
 * @Date: 2021-08-18 16:46:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-18 16:59:05
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
const int mod = 1e9+7;
class Solution
{
public:
    int checkRecord(int n)
    {
        int dp[2][3]={{1,0,0},{0,0,0}};
        while(n--)
        {
            int temp[2][3]={{0,0,0},{0,0,0}};
            // P结尾，Present到场
            for(int j=0;j<=1;j++)
                for(int k=0;k<=2;k++)
                    temp[j][0] = (temp[j][0]+dp[j][k])%mod;
            // A结尾，Absent缺席
            for(int k=0;k<=2;k++)
                temp[1][0]=(temp[1][0]+dp[0][k])%mod;
            // L结尾，Late迟到
            for(int j=0;j<=1;j++)
                for(int k=0;k<=1;k++)
                    temp[j][k+1] = (temp[j][k+1]+dp[j][k])%mod;
            memcpy(dp,temp,sizeof(dp));
        }
        int ans=0;
        for(int j=0;j<=1;j++)
            for(int k=0;k<=2;k++)
                ans = (ans+dp[j][k])%mod;
        return ans;
    }
};

// 下面copy from 题解：矩阵快速幂，时间O(log(n))，空间O(1)
/*
class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    vector<vector<long>> pow(vector<vector<long>> mat, int n) {
        vector<vector<long>> ret = {{1, 0, 0, 0, 0, 0}};
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, mat);
            }
            n >>= 1;
            mat = multiply(mat, mat);
        }
        return ret;
    }

    vector<vector<long>> multiply(vector<vector<long>> a, vector<vector<long>> b) {
        int rows = a.size(), columns = b[0].size(), temp = b.size();
        vector<vector<long>> c(rows, vector<long>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                for (int k = 0; k < temp; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                    c[i][j] %= MOD;
                }
            }
        }
        return c;
    }

    int checkRecord(int n) {
        vector<vector<long>> mat = {{1, 1, 0, 1, 0, 0}, {1, 0, 1, 1, 0, 0}, {1, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0}, {0, 0, 0, 1, 0, 1}, {0, 0, 0, 1, 0, 0}};
        vector<vector<long>> res = pow(mat, n);
        long sum = accumulate(res[0].begin(), res[0].end(), 0ll);
        return (int)(sum % MOD);
    }
};
*/