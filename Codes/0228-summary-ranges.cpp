/*
 * @Author: LetMeFly
 * @Date: 2022-09-07 20:18:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-07 20:22:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    string num2str(int numBegin, int numEnd) {
        if (numBegin == numEnd) {
            return to_string(numBegin);
        }
        else {
            return to_string(numBegin) + "->" + to_string(numEnd);
        }
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};
        
        vector<string> ans;
        int lastBeginNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                ans.push_back(num2str(lastBeginNum, nums[i - 1]));
                lastBeginNum = nums[i];
            }
        }
        ans.push_back(num2str(lastBeginNum, nums.back()));
        return ans;
    }
};