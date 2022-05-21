/*
 * @Author: LetMeFly
 * @Date: 2021-12-29 08:02:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-29 08:10:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < n; j++)
        //         for (int k = 0; k < n; k++)
        //             for (int l = 0; l < n; l++)
        //                 if (nums[i] < nums[j] && nums[j] < nums[k] && nums[k] < nums[l] && nums[i] + nums[j] + nums[k] == nums[l] && i != j && i != k && i != l && j != k && j != l && k != l )
        //                     ans++;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    for (int l = k + 1; l < n; l++)
                        if (nums[i] + nums[j] + nums[k] == nums[l])
                            ans ++;
        return ans;
    }
};