/*
 * @Author: LetMeFly
 * @Date: 2024-07-13 00:24:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-13 00:32:35
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int lastMax = 0, last1 = 0, thisMax = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (__builtin_popcount(nums[i]) != last1) {
                lastMax = thisMax, last1 = __builtin_popcount(nums[i]);
                thisMax = nums[i];
            } else {
                thisMax = max(thisMax, nums[i]);
            }
            if (nums[i] < lastMax) {
                return false;
            }
        }
        return true;
    }
};

#ifdef _WIN32
int main() {
    vector<int> v = {8, 4, 2, 30, 15};
    Solution sol;
    cout << sol.canSortArray(v) << endl;
    return 0;
}
#endif