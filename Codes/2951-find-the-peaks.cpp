/*
 * @Author: LetMeFly
 * @Date: 2024-05-28 22:09:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-28 22:10:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ans;
        for (int i = 1; i < mountain.size() - 1; i++) {
            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
                ans.push_back(i);
                i++;
            }
        }
        return ans;
    }
};