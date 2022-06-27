/*
 * @Author: LetMeFly
 * @Date: 2022-06-27 16:08:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-27 16:11:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        for (int i = 0; i < (1 << nums.size()); i++) {
            vector<int> thisV;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    thisV.push_back(nums[j]);
                }
            }
            sort(thisV.begin(), thisV.end());
            ans.insert(thisV);
        }
        vector<vector<int>> realAns;
        for (auto& v : ans)
            realAns.push_back(v);
        return realAns;
    }
};