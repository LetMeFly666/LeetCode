/*
 * @Author: LetMeFly
 * @Date: 2022-01-19 14:04:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-19 14:09:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FIRSTTRY
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j <= i + k && j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
#endif

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> ma;
        for (int i = 0; i < nums.size(); i++) {
            if (ma[nums[i]]) { // 已有
                if (i + 1 - ma[nums[i]] <= k) {
                    return true;
                }
            }
            ma[nums[i]] = i + 1;
        }
        return false;
    }
};