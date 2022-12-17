/*
 * @Author: LetMeFly
 * @Date: 2022-12-17 10:22:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-17 10:42:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// class Solution {
// public:
//     bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
//         int locG1 = 0, locG2 = 0;
//         for (int locN = 0; locN < nums.size(); locN++) {
//             if (nums[locN] == groups[locG1][locG2]) {
//                 locG2++;
//                 if (locG2 == groups[locG1].size()) {
//                     locG1++, locG2 = 0;
//                 }
//             }
//             else {
//                 locG2 = 0;
//             }
//         }
//     }
// };

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int locN = 0;
        for (vector<int>& v : groups) {
            int locV = 0;
            while (locV < v.size() && locN < nums.size()) {
                if (v[locV] == nums[locN]) {
                    locV++, locN++;
                }
                else {
                    locN -= locV - 1, locV = 0;
                }
            }
            if (locN == nums.size() && locV != v.size())
                return false;
        }
        return true;
    }
};