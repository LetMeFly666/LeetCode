/*
 * @Author: LetMeFly
 * @Date: 2021-08-12 16:50:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-12 19:05:09
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int dp[1000][1000]; // dp[i][j]:从i到j的回文子序列的个数
void debug(int i,int j,int n)
{
    printf("i=%d, j=%d:\n",i,j);
    fi(ii,0,n)
    {
        fi(jj,0,n)
        {
            printf("%2d",dp[ii][jj]);
        }
        puts("");
    }
}
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n=s.size();
        fi(i,0,n)
            fi(j,0,n)
                dp[i][j]=i==j?1:0;
        // int ans=1;
        fi(j,1,n)
        // for(int i=n-1;i>-1;i--)
        {
            for(int i=j-1;i>-1;i--)
            // for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                // debug(i,j,n); //*********
                // ans=max(ans,dp[i][j]);
            } 
        }
        return dp[0][n-1];
        // return ans;
    }
};

int main()
{
    string s;
    while(cin>>s)
    {
        Solution sol;
        cout<<sol.longestPalindromeSubseq(s)<<endl;
    }
    system("pause");
    return 0;
}