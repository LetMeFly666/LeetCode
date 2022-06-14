/*
 * @Author: LetMeFly
 * @Date: 2022-06-13 10:25:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-13 10:25:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0, 0, 0};
        for (int& t : nums)
            cnt[t]++;
        int loc = 0;
        for (int i = 0; i < 3; i++) {
            while (cnt[i]--) {
                nums[loc++] = i;
            }
        }
    }
};