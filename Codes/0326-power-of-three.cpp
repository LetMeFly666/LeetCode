/*
 * @Author: LetMeFly
 * @Date: 2021-09-23 14:44:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-23 14:47:14
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if (n<=0)return false;
//         while(n!=1) {
//             if (n%3) return false;
//             n/=3;
//         }
//         return true;
//     }
// };

// 方法一👆
// 方法二👇

// 3^19=1162261467
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0&&1162261467%n==0;
    }
};