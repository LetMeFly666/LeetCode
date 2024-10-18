/*
 * @Author: LetMeFly
 * @Date: 2024-10-18 22:50:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-18 22:59:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
011100
100100
100011
111111


011100
100100
111000
111111

0111
1001
1110
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (!nums[i]) {
                ans++;
                // nums[i] ^= 1;  // 这个修改与否都无所谓了
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
            }
        }
        return nums[nums.size() - 1] & nums[nums.size() - 2] ? ans : -1;
    }
};