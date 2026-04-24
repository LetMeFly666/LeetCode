/*
 * @Author: LetMeFly
 * @Date: 2026-04-24 13:53:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-24 14:03:28
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
private:
    void cal(vector<int>& idxs, vector<ll>& ans) {
        int n = idxs.size();
        ll total = accumulate(idxs.begin(), idxs.end(), 0LL);
        ll prefix = 0;
        for (int i = 0; i < n; i++) {
            ans[idxs[i]] += (total - prefix - idxs[i]) - (ll)(n - i - 1) * idxs[i];
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
