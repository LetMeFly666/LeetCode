/*
 * @Author: LetMeFly
 * @Date: 2024-05-25 12:20:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-25 12:27:08
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (j - i >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};