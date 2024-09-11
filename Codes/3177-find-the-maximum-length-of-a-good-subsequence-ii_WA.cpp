/*
 * @Author: LetMeFly
 * @Date: 2024-09-07 11:29:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-07 11:54:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(k + 1, 0));
        vector<unordered_map<int, int>> mas(k + 1);
        vector<pair<int, int>> theTop(k + 1);  // top[l]: {最大值对应的nums, 最大值}
        vector<pair<int, int>> theTop2(k + 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int l = 0; l <= k; l++) {
                // update the value
                mas[l][nums[i]]++;
                if (theTop[l].first == nums[i]) {  // 最大的就是nums[i]
                    mas[l][nums[i]] = max(mas[l][nums[i]], theTop2[l].second + 1);
                } else if (l > 0) {  // 最大的是另一个数
                    mas[l][nums[i]] = max(mas[l][nums[i]], theTop[l - 1].second + 1);
                }
                // 维护top2
                int maxVal = mas[l][nums[i]];
                if (maxVal <= theTop2[l].second) {
                    continue;
                }
                if (maxVal <= theTop[l].second) {
                    if (nums[i] == theTop[l].first) {
                        continue;
                    }
                    theTop2[l] = {nums[i], maxVal};
                }
                else {
                    if (nums[i] == theTop[l].first) {
                        theTop[l].second = maxVal;
                    } else {
                        theTop2[l] = theTop[l];
                        theTop[l] = {nums[i], maxVal};
                    }
                }
            }
        }
        int ans = 0;
        for (int l = 0; l <= k; l++) {
            ans = max(ans, theTop[l].second);
        }
        return ans;
    }
};