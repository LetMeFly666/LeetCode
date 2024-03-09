/*
 * @Author: LetMeFly
 * @Date: 2024-03-09 18:10:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-09 18:25:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
1 2 3

      1
    12  2
 123   23  3
*/

typedef long long ll;
typedef pair<ll, int> pli;
class Solution {
public:
    ll kSum(vector<int>& nums, int k) {
        ll sum = 0;
        for (int& t : nums) {
            if (t >= 0) {
                sum += t;
            }
            else {
                t = -t;
            }
        }
        sort(nums.begin(), nums.end());
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({nums[0], 0});
        ll toDesc = 0;
        for (int i = 1; i < k; i++) {
            auto [nowSum, th] = pq.top();
            toDesc = nowSum;
            pq.pop();
            if (th == nums.size() - 1) {
                continue;
            }
            pq.push({nowSum + nums[th + 1], th + 1});
            pq.push({nowSum - nums[th] + nums[th + 1], th + 1});
        }
        return sum - toDesc;
    }
};