/*
 * @Author: LetMeFly
 * @Date: 2025-03-29 10:47:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-29 10:52:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        for (int i = 0; i < edges.size(); i++) {
            int index = i, next = edges[i], cnt = -1;
            while (next >= 0) {
                index = next;
                next = edges[index];
                edges[index] = --cnt;
            }
            if (next != -1) {
                ans = max(ans, next - edges[index]);
            }
        }
        return ans;
    }
};