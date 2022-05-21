/*
 * @Author: LetMeFly
 * @Date: 2021-08-15 11:42:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-15 12:15:51
 */
// // 普通dp
// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;
// static const int mod = 1000000007;
// int dp[52][52][52];
// int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
// class Solution
// {
// public:
//     int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
//     {
//         ll ans=0;
//         mem(dp);
//         dp[0][startRow][startColumn]=1;
//         fi(i,0,maxMove)
//         {
//             fi(j,0,m)
//             {
//                 fi(k,0,n)
//                 {
//                     int count=dp[i][j][k];
//                     if(count>0)
//                     {
//                         for(int d=0;d<4;d++)
//                         {
//                             int tx=j+dir[d][0];
//                             int ty=k+dir[d][1];
//                             if(tx>=0&&tx<m&&ty>=0&&ty<n)
//                             {
//                                 dp[i+1][tx][ty] = (dp[i+1][tx][ty] + count) % mod;
//                             }
//                             else
//                             {
//                                 ans = (ans + count) % mod;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// 就地滚动
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int dp[2][52][52];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
static const int mod = 1000000007;
class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        ll ans=0;
        mem(dp);
        int nowUsing=0;
        dp[nowUsing][startRow][startColumn]=1;
        fi(i,0,maxMove)
        {
            int newUsing = (nowUsing==0);
            // dbg(newUsing); //********
            fi(ti,0,m)
                fi(tj,0,n)
                    dp[newUsing][ti][tj]=0;
            fi(nx,0,m)
            {
                fi(ny,0,n)
                {
                    int count=dp[nowUsing][nx][ny];
                    
                    if(count>0)
                    {
                        fi(d,0,4)
                        {
                            int tx=nx+dir[d][0];
                            int ty=ny+dir[d][1];
                            if(tx>=0&&tx<m&&ty>=0&&ty<n)
                            {
                                dp[newUsing][tx][ty]=(dp[newUsing][tx][ty]+count)%mod;
                            }
                            else
                            {
                                ans=(ans+count)%mod;
                            }                            
                        }
                    }
                }
            }
            fi(ti,0,m)
                fi(tj,0,n)
                    dp[nowUsing][ti][tj]=dp[newUsing][ti][tj];
            nowUsing=newUsing;
        }
        return ans;
    }
};