/*
 * @Author: LetMeFly
 * @Date: 2021-10-23 18:51:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-23 18:54:53
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
//     vector<int> constructRectangle(int area) {
//         vector<int> ans(2);
//         ans[0] = ans[1] = sqrt(area);
//         if (area % ans[0]) {
//             ans[0]++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2);
        for (int i = sqrt(area); i > 0; i--) {
            if (area % i == 0) {
                ans[0] = area / i;
                ans[1] = i;
                return ans;
            }
        }
        return ans; // Useless
    }
};