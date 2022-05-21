/*
 * @Author: LetMeFly
 * @Date: 2021-11-19 19:27:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-19 19:41:35
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
//     int integerReplacement(int n) {
//         int ans = 0;
//         while (n > 1) {
//             if (n % 2) {
//                 n--;
//             }
//             else {
//                 n /= 2;
//             }
//             ans++;
//         }
//         return ans;
//     }
// };

class Solution {
private:
    unordered_map<int, int> ma;
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (ma[n]) return ma[n];
        if (n % 2) return ma[n] = 2 + min(integerReplacement(n / 2 + 1), integerReplacement(n / 2));
        else return ma[n] = 1 + integerReplacement(n / 2);
    }
};