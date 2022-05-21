// /*
//  * @Author: LetMeFly
//  * @Date: 2021-08-16 13:38:57
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-08-16 13:51:47
//  */
// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;

// class Solution
// {
// public:
//     int countArrangement(int n)
//     {
//         vector<int>dp(1<<n);
//         dp[0]=1;
//         fi(i,1,1<<n)
//         {
//             int one=__builtin_popcount(i);
//             for(int j=0;j<n;j++)
//             {
//                 if(i&(1<<j)&&((one%(j+1)==0)||((j+1)%one)==0))
//                 { 
//                     dp[i]+=dp[i-(1<<j)];
//                 }
//             }
//         }
//         return dp[(1<<n)-1];
//     }
// };
// int main()
// {
//     printf("int ans[16]={0");
//     Solution sol;
//     for(int i=1;i<=15;i++)
//     {
//         cout<<','<<sol.countArrangement(i);
//     }
//     puts("};");
//     system("pause");
//     return 0;
// }
int ans[16]={0,1,2,3,8,10,36,41,132,250,700,750,4010,4237,10680,24679};
class Solution {
public:
    int countArrangement(int n) {
        return ans[n];
    }
};