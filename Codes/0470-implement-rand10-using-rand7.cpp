// /*
//  * @Author: LetMeFly
//  * @Date: 2021-09-05 19:56:57
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-09-05 19:59:25
//  */
// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;
// // The rand7() API is already defined for you.
// // int rand7();
// // @return a random integer in the range 1 to 7

// int rand7(){
//     return rand() % 7 + 1;
// }

// class Solution {
// public:
//     int rand10() {
//         return rand7() * 10 / 7;
//     }
// };

// FWb
class Solution {
public:
    int rand10() {
        int a, b, idx;
        while (true) {
            a = rand7();
            b = rand7();
            idx = b + (a - 1) * 7;
            if (idx <= 40) {
                return 1 + (idx - 1) % 10;
            }
            a = idx - 40;
            b = rand7();
            // get uniform dist from 1 - 63
            idx = b + (a - 1) * 7;
            if (idx <= 60) {
                return 1 + (idx - 1) % 10;
            }
            a = idx - 60;
            b = rand7();
            // get uniform dist from 1 - 21
            idx = b + (a - 1) * 7;
            if (idx <= 20) {
                return 1 + (idx - 1) % 10;
            }
        }
    }
};