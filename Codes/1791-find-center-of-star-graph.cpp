/*
 * @Author: LetMeFly
 * @Date: 2022-02-18 10:17:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-02-18 10:18:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ? edges[0][0] : edges[0][1];
    }
};