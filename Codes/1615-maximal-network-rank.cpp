/*
 * @Author: LetMeFly
 * @Date: 2023-03-15 09:48:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-15 09:53:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        vector<int> cnt(n);
        unordered_set<int> se;
        for (vector<int>& road : roads) {
            cnt[road[0]]++;
            cnt[road[1]]++;
            se.insert(road[0] * 1000 + road[1]);
            se.insert(road[1] * 1000 + road[0]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, cnt[i] + cnt[j] - (int)se.count(i * 1000 + j));
            }
        }
        return ans;
    }
};