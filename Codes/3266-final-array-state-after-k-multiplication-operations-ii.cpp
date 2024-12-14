/*
 * @Author: LetMeFly
 * @Date: 2024-12-14 15:12:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-14 17:42:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/* 
1 3 5 6
2

                  min
2 3 5 6            0
4 3 5 6            1
4 6 5 6            0
8 6 5 6            2
8 6 10 6           1
8 12 10 6          3
8 12 10 12         0
16 12 10 12        2
16 12 20 12        1
16 24 20 12        3
16 24 20 24        0
...
*/
typedef long long ll;
const ll MOD = 1e9+7;
class Solution {
private:
    ll pow(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        vector<pair<ll, int>> h;
        for (int i = 0; i < nums.size(); i++) {
            h.push_back({nums[i], i});
        }
        make_heap(h.begin(), h.end(), greater<>());
        ll M = *max_element(nums.begin(), nums.end());
        for (; k && h[0].first < M; k--) {
            pop_heap(h.begin(), h.end(), greater<>());
            h.back().first *= multiplier;  // 这里不能取模，因为取模后可能导致一个本来大于M的数又小于M了。
            push_heap(h.begin(), h.end(), greater<>());
        }
        sort(h.begin(), h.end());
        for (int i = 0; i < h.size(); i++) {
            auto& [val, index] = h[i];
            nums[index] = val % MOD * pow(multiplier, k / nums.size() + (i < k % nums.size())) % MOD;
        }
        return nums;
    }
};