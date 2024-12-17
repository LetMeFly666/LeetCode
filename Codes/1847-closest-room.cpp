/*
 * @Author: LetMeFly
 * @Date: 2024-12-16 10:12:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-16 10:54:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        vector<int> queryIdx(queries.size());
        iota(queryIdx.begin(), queryIdx.end(), 0);
        sort(queryIdx.begin(), queryIdx.end(), [&](int i, int j) {
            return queries[i][1] > queries[j][1];
        });
        sort(rooms.begin(), rooms.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });
        set<int> canIds;
        vector<int> ans(queries.size());
        for (int locR = 0, locQ = 0; locQ < queryIdx.size(); locQ++) {
            int queryId = queries[queryIdx[locQ]][0], size = queries[queryIdx[locQ]][1];
            while (locR < rooms.size() && rooms[locR][1] >= size) {
                canIds.insert(rooms[locR++][0]);
            }
            if (canIds.empty()) {
                ans[queryIdx[locQ]] = -1;
                continue;
            }
            set<int>::iterator it = canIds.lower_bound(queryId);
            int idDiff = abs(queryId - *it);
            if (it != canIds.begin() && abs(queryId - *prev(it)) <= idDiff) {
                it--;
            }
            ans[queryIdx[locQ]] = *it;
        }
        return ans;
    }
};