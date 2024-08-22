/*
 * @Author: LetMeFly
 * @Date: 2024-08-22 09:59:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-22 11:34:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


// typedef long long ll;
/*
100: 001 010 011 -> 101 110 111
100: 001 010 011 100 -> 101 110 111 1100
对于x的二进制的每个1：
    如果n的这一位是0，则将其置为1
    否则(这一位是1)，则在此插入一个1
2^27=134,217,728>10^8
*/
// class Solution {
// private:
//     inline void add1(ll& ans, int& lenAns) {
//         ans |= (1 << lenAns);
//         lenAns++;
//     }
// public:
//     ll minEnd(int n, int x) {
//         ll ans = 0;
//         int lenAns = 0;
//         for (int i = 0; i < 27; i++) {
//             if ((x & (1 << i)) && (x & (1 << x))) {  // n和x的这一位都是1
//                 add1(ans, lenAns);
//                 add1(ans, lenAns);
//             }
//             else if ((x & (1 << i)) || (x & (1 << x))) {  // 其中1个是1
//                 add1(ans, lenAns);
//             }
//         }
//         return ans;
//     }
// };

/*
001: 000 001 010 -> 001 011 011  x
001: 000 001 010 -> 001 011 0101 √
111: 000 001 -> 111 1111 √
将x的每一个1插入到n对应的位置
*/
// class Solution {
// public:
//     ll minEnd(int n, int x) {
//         n--;
//         ll ans = 0;
//         int lenAns = 0;
//         for (int i = 0; i < 27; i++) {
//             if (x & (1 << i)) {
//                 ans |= (1 << lenAns);
//                 lenAns++;
//             }
//             if (n & (1 << i)) {
//                 ans |= (1 << lenAns);
//             }
//             lenAns++;
//         }
//         return ans;
//     }
// };

/*
将x每个0的位置设置为n-1的二进制
*/
typedef long long ll;

class Solution {
public:
    ll minEnd(ll n, ll x) {
        n--;
        for (int in = 0, ix = 0; in < 27; in++, ix++) {
            while ((x >> ix) & 1) {  // 找到下一个为0的位置
                ix++;
            }
            x |= (((n >> in) & 1) << ix);
        }
        return x;
    }
};

#ifdef _WIN32
int main() {
    Solution sol;
    assert(sol.minEnd(3, 4) == 6);
    assert(sol.minEnd(2, 7) == 15);
    assert(sol.minEnd(3, 1) == 5);
    return 0;
}
#endif