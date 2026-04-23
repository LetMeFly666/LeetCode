/*
 * @Author: LetMeFly
 * @Date: 2026-04-23 22:33:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-23 22:43:47
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
1 3 7 8
1: 3-1 + 7-1 + 8-1 = 3+7+8 - 3*1 = 1+3+7+8 - 4*1
3: 3-1 + 7-3 + 8-3 = -1+7+8 + 3 - 2*3 = ↑ + 2*(1-3)
7: 7-1 + 7-3 + 8-7 = ↑ + 7-3 + 3-7
*/
typedef long long ll;
class Solution {
private:
    ll cal(vector<int>& idxs) {
        if (idxs.size() == 1) {
            return 0;
        }

    }
public:
    vector<ll> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> ma;
        for (int i = 0; i < nums.size(); i++) {
            ma[nums[i]].push_back(i);
        }

        vector<ll> ans;
        ans.reserve(nums.size());
        for (auto&& [_, idxs] : ma) {
            ans.push_back(cal(idxs));
        }
        return ans;
    }
};