/*
 * @Author: LetMeFly
 * @Date: 2023-03-17 12:58:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-17 13:01:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        for (int& q : queries) {
            q = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
        }
        return queries;
    }
};