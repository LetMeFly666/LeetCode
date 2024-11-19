/*
 * @Author: LetMeFly
 * @Date: 2024-11-19 14:30:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-19 14:37:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> shortest(n);
        vector<vector<int>> fromList(n);
        for (int i = 1; i < n; i++) {
            fromList[i].push_back(i - 1);
            shortest[i] = i;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int from = queries[i][0], to = queries[i][1];
            fromList[to].push_back(from);
            for (int j = to; j < n; j++) {
                for (int from : fromList[j]) {
                    shortest[j] = min(shortest[j], shortest[from] + 1);
                }
            }
            ans[i] = shortest.back();
        }
        return ans;
    }
};