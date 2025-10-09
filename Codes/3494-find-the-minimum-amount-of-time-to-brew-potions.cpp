/*
 * @Author: LetMeFly
 * @Date: 2025-10-09 22:19:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-09 22:39:54
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll minTime(vector<int>& skill, vector<int>& mana) {
        vector<ll> times(skill.size());
        // finishTime[0] = skill[0] * mana[0];
        // for (int i = 1; i < skill.size(); i++) {
        //     finishTime[i] = finishTime[i - 1] + mana[i] * skill[i];
        // }
        for (int m : mana) {
            ll delay = 0;
            ll nowFinish = times[0] + skill[0] * m;
            for (int i = 1; i < skill.size(); i++) {
                delay = max(delay, times[i] - nowFinish);
                nowFinish = max(nowFinish, times[i]) + skill[i] * m;
            }
            times[0] += delay + skill[0] * m;
            for (int i = 1; i < skill.size(); i++) {
                times[i] = times[i - 1] + skill[i] * m;
            }
        }
        return times.back();
    }
};