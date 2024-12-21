/*
 * @Author: LetMeFly
 * @Date: 2024-12-21 17:49:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-21 17:53:37
 * @Description: 没有全程在写
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&k](const vector<int>& a, const vector<int>& b) {
            return a[k] > b[k];
        });
        return score;
    }
};