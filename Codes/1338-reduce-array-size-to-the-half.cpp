/*
 * @Author: LetMeFly
 * @Date: 2024-12-15 14:57:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-15 15:06:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // WA，需要以pair.second为依据排序
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> ma;
        for (int t : arr) {
            ma[t]++;
        }
        vector<pair<int, int>> times(ma.begin(), ma.end());
        sort(times.begin(), times.end(), greater<>());
        int ans = 0;
        int cnt = 0;
        for (int i = times.size() - 1; cnt < arr.size() / 2; ans++, i--) {
            printf("times[%d] = {%d, %d}\n", i, times[i].first, times[i].second);  //********
            cnt += times[i].second;
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> ma;
        for (int t : arr) {
            ma[t]++;
        }
        vector<int> times;
        for (auto&& [_, t] : ma) {
            times.push_back(t);
        }
        sort(times.begin(), times.end());
        int ans = 0;
        for (int cnt = 0, i = times.size() - 1; cnt < arr.size() / 2; ans++, i--) {
            cnt += times[i];
        }
        return ans;
    }
};
#endif  // FirstTry