/*
 * @Author: LetMeFly
 * @Date: 2024-07-24 12:45:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-24 12:45:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> stones(nums.begin(), nums.end());
        for (int i = 0; i < moveFrom.size(); i++) {
            stones.erase(moveFrom[i]);
            stones.insert(moveTo[i]);
        }
        vector<int> ans(stones.begin(), stones.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};