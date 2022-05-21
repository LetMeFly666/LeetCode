/*
 * @Author: LetMeFly
 * @Date: 2021-11-08 20:49:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-08 20:54:47
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution {
public:
    string getHint(string secret, string guess) {
        int remainSe[10] = {0};
        int remainGu[10] = {0};
        int A = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                A++;
            }
            else {
                remainSe[secret[i] - '0']++;
                remainGu[guess[i] - '0']++;
            }
        }
        int B = 0;
        for (int i = 0; i < 10; i++) {
            B += min(remainSe[i], remainGu[i]);
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};