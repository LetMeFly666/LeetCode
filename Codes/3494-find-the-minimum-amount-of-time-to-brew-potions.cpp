/*
 * @Author: LetMeFly
 * @Date: 2025-10-09 22:19:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-09 22:49:27
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
            ll delay = 0;
            ll nowFinish = times[0] + skill[0] * m;
            for (int i = 1; i < skill.size(); i++) {
                delay += max(0ll, times[i] - nowFinish);
                nowFinish = max(nowFinish, times[i]) + skill[i] * m;
            }
            times[0] += delay + skill[0] * m;
            for (int i = 1; i < skill.size(); i++) {
                times[i] = times[i - 1] + skill[i] * m;
            }
            // cout << times[0] << endl;  // *****
        }
        return times.back();
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[1,5,2,4]
[5,1,4,2]

110

巫师0完成时间：
5
53
58
88
*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        vector<int> va = stringToVector(a), vb = stringToVector(b);
        Solution sol;
        cout << sol.minTime(va, vb) << endl;
    }
    return 0;
}
#endif