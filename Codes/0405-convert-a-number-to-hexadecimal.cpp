/*
 * @Author: LetMeFly
 * @Date: 2021-10-02 13:32:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-02 14:07:52
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

template<class type>
void debug(type a[], int n, string c) {
    for (int i = 0; i < n; i++) {
        cout << a[i] <<c;
    }
    puts("");
}

template<class type>
void debug(type a[], int n) {
    debug(a, n, " ");
}

char duiYing[] = "0123456789abcdef";

// class Solution {
// public:
//     string toHex(int num) {
//         if (num == -2147483648)
//             return "80000000";
//         bool bit[32] = {0};
//         if (num < 0) {
//             num = -num;
//             bit[0] = true;
//         }
//         int loc = 31;
//         while (num) {
//             bit[loc--] = (num & 1) != 0;
//             num >>= 1;
//         }
//         if (bit[0]) {
//             for (int i = 1; i < 32; i++) {
//                 bit[i] = bit[i] ? false : true;
//             }
//             debug(bit, 32, "");
//             int jinWei = 1; // 取反后+1
//             for (int i = 31; i > 0; i--) {
//                 int thisBit = jinWei + bit[i];
//                 bit[i] = thisBit % 2;
//                 jinWei = thisBit / 2;
//             }
//         }
//         debug(bit, 32, "");
//         string ans;
//         bool addZero = false;
//         for (int i = 0; i < 8; i++) {
//             int thisNum = 0;
//             for (int j = i * 4; j < i * 4 + 4; j++) {
//                 thisNum *= 2;
//                 thisNum += bit[j];
//             }
//             if (thisNum == 0 && !addZero) continue;
//             addZero = true;
//             ans += duiYing[thisNum];
//         }
//         if (ans.empty())
//             ans = '0';
//         return ans;
//     }
// };

class Solution {
public:
    string toHex(int num) {
        if (num == -2147483648)
            return "80000000";
        bool bit[32] = {0};
        int loc = 31;
        for (int i = 0; i < 32; i++) {
            bit[31 - i] = (num & (1 << i)) != 0;
        }
        // debug(bit, 32, "");
        string ans;
        bool addZero = false;
        for (int i = 0; i < 8; i++) {
            int thisNum = 0;
            for (int j = i * 4; j < i * 4 + 4; j++) {
                thisNum *= 2;
                thisNum += bit[j];
            }
            if (thisNum == 0 && !addZero) continue;
            addZero = true;
            ans += duiYing[thisNum];
        }
        if (ans.empty())
            ans = '0';
        return ans;
    }
};

int main() {
    int n;
    while(cin >> n) {
        Solution sol;
        cout << sol.toHex(n) << endl;
    }
    return 0;
}