/*
 * @Author: LetMeFly
 * @Date: 2024-09-21 14:02:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-21 14:05:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<ll> score(edges.size());
        ll M = 0;
        int ans = -1;
        for (int i = 0; i < edges.size(); i++) {
            score[edges[i]] += i;
            if (score[edges[i]] > M) {
                M = score[edges[i]];
                ans = edges[i];
            } else if (score[edges[i]] == M) {
                ans = min(ans, edges[i]);
            }
        }
        return ans;
    }
};