/*
 * @Author: LetMeFly
 * @Date: 2021-09-04 21:45:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-04 21:47:01
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

int a[101]={0,1};
class Solution {
public:
    int fib(int n) {
        for(int i=2;i<=n;i++)
        {
            a[i] = (a[i-1] + a[i-2]) % 1000000007;
        }
        return a[n];
    }
};