/*
 * @Author: LetMeFly
 * @Date: 2024-10-11 22:32:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-11 22:53:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ll ans = 0;
        unordered_map<int, int> ma;
        for (int t : nums1) {
            if (t % k) {
                continue;
            }
            t /= k;
            int sqrt_ = sqrt(t);
            for (int i = 1; i <= sqrt_; i++) {
                if (t % i == 0) {
                    ma[i]++;
                    ma[t / i]++;
                }
            }
            if (sqrt_ * sqrt_ == t) {
                ma[sqrt_]--;
            }
        }
        for (int t : nums2) {
            ans += ma[t];
        }
        return ans;
    }
};