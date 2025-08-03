/*
 * @Author: LetMeFly
 * @Date: 2025-08-03 22:53:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-03 23:30:35
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
假设要交换的有 3 4 30 40

b1: [3, 30]
b2: [4, 40]

则min: 3+4

*/
typedef long long ll;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> diffTimes;
        int m = INT_MAX;
        for (int t : basket1) {
            diffTimes[t]++;
            m = min(m, t);
        }
        for (int t : basket2) {
            diffTimes[t]--;
            m = min(m, t);
        }
        vector<int> change;
        for (auto [val, times] : diffTimes) {
            if (!times) {
                continue;
            }
            if (times % 2) {
                return -1;
            }
            for (int i = 0; i < abs(times) / 2; i++) {
                change.push_back(val);
            }
        }
        sort(change.begin(), change.end());
        int ans = 0;
        for (int i = 0; i < change.size() / 2; i++) {
            ans += min(change[i], 2 * m);
        }
        return ans;
    }
};

/*
[4,2,2,2]
[1,4,1,2]

1
*/
#if defined(_WIN32) || defined(__APPLE__)
int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        vector<int> v1 = stringToVector(s1), v2 = stringToVector(s2);
        Solution sol;
        cout << sol.minCost(v1, v2) << endl;
    }
    return 0;
}
#endif