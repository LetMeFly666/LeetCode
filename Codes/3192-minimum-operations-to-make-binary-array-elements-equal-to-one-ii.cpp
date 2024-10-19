/*
 * @Author: LetMeFly
 * @Date: 2024-10-19 09:20:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-19 09:25:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
01101
10010
11101
11110
11111


n o
0 1 翻
0 0 不
1 1 不
1 0 翻
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, original = 1;
        for (int t : nums) {
            if (t ^ original) {
                ans++;
                original ^= 1;
            }
        }
        return ans;
    }
};