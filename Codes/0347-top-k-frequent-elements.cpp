/*
 * @Author: LetMeFly
 * @Date: 2022-10-01 09:53:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-01 09:55:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef pair<int, int> pii;

bool cmp(const pii& a, const pii& b) {
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ma;
        for (int& t : nums) {
            ma[t]++;
        }
        vector<pii> v;
        for (auto thisPair : ma) {
            v.push_back(thisPair);
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};