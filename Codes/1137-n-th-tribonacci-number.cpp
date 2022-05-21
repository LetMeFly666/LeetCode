/*
 * @Author: LetMeFly
 * @Date: 2021-08-08 11:01:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-08 11:08:29
 */

// 方法一：easy
// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;
// int a[38]={0,1,1};

// class Solution {
// public:
//     int tribonacci(int n) {
//         return a[n];
//     }
//     Solution(){
//         for(int i=3;i<=37;i++)
//         {
//             a[i]=a[i-1]+a[i-2]+a[i-3];
//         }
//     }
// };

// 方法二：只用4个空间
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution {
public:
    int tribonacci(int n) {
        int a[3]={0,1,1};
        if(n<3)return a[n];
        for(int i=3;i<=n;i++)
        {
            int newOne=0;
            fi(j,0,3)newOne+=a[j];
            fi(j,0,2)a[j]=a[j+1];
            a[2]=newOne;
        }
        return a[2];
    }
};