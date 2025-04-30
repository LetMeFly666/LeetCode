/*
 * @Author: LetMeFly
 * @Date: 2025-04-29 23:46:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-29 23:58:18
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        vector<ll> suffix(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            suffix[i + 1] = suffix[i] + nums[i];
        }
        ll ans = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            // while ((suffix[r + 1] - suffix[l]) * (r - l + 1) >= k && l < r) {  // 不可，否则可能因为l=r退出循环，导致[i, i]大于k但仍被统计
            while ((suffix[r + 1] - suffix[l]) * (r - l + 1) >= k) {
                l++;
            }
            ans += r - l + 1;
            // cout << "[" << l << ", " << r << "]" << endl;
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[2,1,4,3,5]
10

6
*/
/*
[9,5,3,8,4,7,2,7,4,5,4,9,1,4,8,10,8,10,4,7]
4

3
*/
int main() {
    string s;
    int k;
    while (cin >> s >> k) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.countSubarrays(v, k) << endl;
    }
    return 0;
}
#endif