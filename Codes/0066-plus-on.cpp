/*
 * @Author: LetMeFly
 * @Date: 2021-10-21 17:46:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-21 17:52:35
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
    vector<int> plusOne(vector<int>& digits) {
        int add = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += add;
            if (digits[i] <= 9) {
                add = 0;
                break;
            } else {
                digits[i] = 0;
            }
        }
        if (add) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};