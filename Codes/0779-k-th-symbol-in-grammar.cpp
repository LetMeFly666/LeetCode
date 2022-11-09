/*
 * @Author: LetMeFly
 * @Date: 2022-10-20 08:01:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-20 08:10:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
0
01
0110
01101001

*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1 && k == 1)
            return 0;
        int from = kthGrammar(n - 1, (k + 1) / 2);
        return (from != k % 2) ? 0 : 1;
    }
};