/*
 * @Author: LetMeFly
 * @Date: 2025-05-23 23:35:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-23 23:45:02
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        vector<int> diff(nums.size() + 1);
        priority_queue<int> pq;
        for (int in = 0, iq = 0, cnt = 0; in < nums.size(); in++) {
            cnt += diff[in];
            while (iq < queries.size() && queries[iq][0] <= in) {
                pq.push(queries[iq++][1]);
            }
            while (cnt < nums[in] && pq.size() && pq.top() >= in) {
                cnt++;
                diff[pq.top() + 1]--;
                pq.pop();
            }
            if (cnt < nums[in]) {
                return -1;
            }
        }
        return pq.size();
    }
};