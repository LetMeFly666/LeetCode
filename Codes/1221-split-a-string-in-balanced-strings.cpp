/*
 * @Author: LetMeFly
 * @Date: 2021-09-07 08:27:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-07 08:37:22
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
//     int balancedStringSplit(string s) {
//         int sl = 0, sr = 0;
//         for(char &c:s){
//             if (c == 'L'){
//                 sl++;
//             }
//             else{
//                 sr++;
//             }
//         }
//         return min(sl, sr);
//     }
// };

// class Solution {
// public:
//     int balancedStringSplit(string s) {
//         int ans = 0;
//         bool l = s[0] == 'L';
//         bool zero = false;
//         int n = s.size();
//         for (int i = 1; i < n; i++) {
//             if (zero) {
//                 zero = false;
//                 l = s[i] == 'L';
//             }
//             else if (l != (s[i] == 'L')) {
//                 ans++;
//                 zero = true;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int sl = 0;
        for (char &c : s) {
            if (c == 'L') {
                sl++;
            }
            else {
                sl--;
            }
            if (!sl) {
                ans ++;
            }
        }
        return ans;
    }
};