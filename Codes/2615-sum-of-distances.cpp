/*
 * @Author: LetMeFly
 * @Date: 2026-04-23 22:33:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-24 13:44:32
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
@deprecated 注释未采用
1 3 7 8
1: 3-1 + 7-1 + 8-1 = 3+7+8 - 3*1 = 1+3+7+8 - 4*1
3: 3-1 + 7-3 + 8-3 = -1+7+8 + 3 - 2*3 = ↑ + 2*(1-3)
7: 7-1 + 7-3 + 8-7 = ↑ + 7-3 + 3-7
*/
typedef long long ll;
class Solution {
private:
    void cal(vector<int>& idxs, vector<ll>& ans) {
        int n = idxs.size();
        vector<ll> suffix(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + idxs[i];
        }
        ll prefix = 0;
        for (int i = 0; i < n; i++) {
            ans[idxs[i]] += suffix[i + 1] - (ll)(n - i - 1) * idxs[i];
            ans[idxs[i]] += (ll)i * idxs[i] - prefix;
            prefix += idxs[i];
        }
    }
public:
    vector<ll> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> ma;
        for (int i = 0; i < nums.size(); i++) {
            ma[nums[i]].push_back(i);
        }

        vector<ll> ans(nums.size());
        for (auto&& [_, idxs] : ma) {
            cal(idxs, ans);
        }
        return ans;
    }
};
