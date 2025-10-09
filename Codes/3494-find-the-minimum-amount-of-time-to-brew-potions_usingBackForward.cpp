/*
 * @Author: LetMeFly
 * @Date: 2025-10-09 22:19:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-09 22:57:06
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll minTime(vector<int>& skill, vector<int>& mana) {
        vector<ll> times(skill.size());
        for (int m : mana) {
            ll nowFinish = times[0] + skill[0] * m;
            for (int i = 1; i < skill.size(); i++) {
                nowFinish = max(nowFinish, times[i]) + skill[i] * m;
            }
            times.back() = nowFinish;
            for (int i = skill.size() - 2; i >= 0; i--) {
                times[i] = times[i + 1] - skill[i] * m;
            }
        }
        return times.back();
    }
};