/*
 * @Author: LetMeFly
 * @Date: 2026-06-26 12:52:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-26 13:06:36
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
s[i]: 0..i中target比非target多几次
f[i]: 以i为右边界的数组中有多少“主target数组”
f[a+1]: 
  - 若nums[a+1]是target，则以a为右边界的数组加上nums[a+1]都还是“主target数组”（来源1），并且满足s[i]=s[a]的位置i为左边界的数组到a为止的子数组target正好占一半，加上nums[a+1]则能变成“主target数组”（来源2），即f[a+1]=f[a]+cnt[s[a]]，其中cnt[s[a]]是历史上s[a]出现的次数
  - 若nums[a+1]不是target，同理，f[a+1]=f[a]-cnt[s[a+1]]
*/
typedef long long ll;
class Solution {
public:
    ll countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        ll ans = 0, s = 0, f = 0;
        for (int t : nums) {
            if (t == target) {
                f += cnt[s++];
            } else {
                f -= cnt[--s];
            }
            ans += f;
            cnt[s]++;
        }
        return ans;
    }
};
