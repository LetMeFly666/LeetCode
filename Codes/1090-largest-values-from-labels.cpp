/*
 * @Author: LetMeFly
 * @Date: 2023-05-23 11:46:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-23 11:50:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> v(values.size());
        for (int i = 0; i < values.size(); i++) {
            v[i] = {values[i], labels[i]};
        }
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        unordered_map<int, int> ma;
        int cnt = 0;
        int ans = 0;
        for (auto&& [value, label] : v) {
            if (ma[label] == useLimit) {
                continue;
            }
            ma[label]++;
            cnt++;
            ans += value;
            if (cnt == numWanted) {
                break;
            }
        }
        return ans;
    }
};