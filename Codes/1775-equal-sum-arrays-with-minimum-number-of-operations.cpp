/*
 * @Author: LetMeFly
 * @Date: 2022-12-07 09:48:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-07 10:27:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
#endif

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (s1 > s2)
            swap(nums1, nums2);
        int times[6] = {0};
        for (int& t : nums1)
            times[t - 1]++;
        for (int& t : nums2)
            times[6 - t]++;
        int ans = 0;
        int loc = 0;
        int diff = abs(s2 - s1);
        while (diff) {
            int perChange = 6 - loc - 1;
            if (!perChange)
                break;
            int maxChange = times[loc] * perChange;
            int realChange = min(maxChange, diff);
            diff -= realChange;
            int changeTimes = realChange / perChange + (realChange % perChange != 0);
            ans += changeTimes;
            // dbg(perChange);
            // dbg(maxChange);
            // dbg(realChange);
            // dbg(changeTimes);
            // dbg(ans);
            // dbg(diff);
            loc++;
        }
        return diff ? -1 : ans;
    }
};


/*
[1,1,1,1,1,1,1]
[6]

*/

#ifdef _WIN32
int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        vector<int> v1 = stringToVector(s1);
        vector<int> v2 = stringToVector(s2);
        Solution sol;
        cout << sol.minOperations(v1, v2) << endl;
    }
    return 0;
}
#endif