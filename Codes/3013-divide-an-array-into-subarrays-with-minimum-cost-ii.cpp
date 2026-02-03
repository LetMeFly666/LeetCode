/*
 * @Author: LetMeFly
 * @Date: 2026-02-03 21:39:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-03 22:01:16
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll minimumCost(vector<int>& nums, int k, int dist) {
        multiset<ll> stage(nums.begin() + 1, nums.begin() + dist + 2), candidate;
        ll ans = accumulate(nums.begin() + 1, nums.begin() + dist + 2, 0ll), nowAns = ans;
        for (int end = dist + 2; end < nums.size(); end++) {
            int in = nums[end], out = nums[end - dist - 1];
            
            // out
            multiset<ll>::iterator it = candidate.find(out);
            if (it != candidate.end()) {
                candidate.erase(it);
            } else {
                stage.erase(stage.find(out));
                nowAns -= out;
            }

            // in
            if (in < *stage.rbegin()) {
                stage.insert(in);
                nowAns += in;
            } else {
                candidate.insert(in);
            }

            // resize
            if (stage.size() == k - 1) {
                int newActor = *candidate.begin();
                candidate.erase(candidate.begin());
                stage.insert(newActor);
                nowAns += newActor;
            } else if (stage.size() == k + 1) {
                int retiree = *stage.rbegin();
                stage.erase(prev(stage.end()));
                nowAns -= retiree;
                candidate.insert(retiree);
            }

            ans = max(ans, nowAns);
        }
        return ans;
    }
};
