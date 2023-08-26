/*
 * @Author: LetMeFly
 * @Date: 2023-08-26 09:24:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-26 09:30:08
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    string genStr(int l, int r) {
        if (l == r) {
            return to_string(l);
        }
        return to_string(l) + "->" + to_string(r);
    }

public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (!nums.size()) {
            return {};
        }
        vector<string> ans;
        int indexFrom = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] != nums[i - 1] + 1) {
                ans.push_back(genStr(nums[indexFrom], nums[i - 1]));
                indexFrom = i;
            }
        }
        ans.push_back(genStr(nums[indexFrom], nums.back()));
        return ans;
    }
};