/*
 * @Author: LetMeFly
 * @Date: 2025-03-09 13:49:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-09 14:03:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int getAns(vector<vector<int>>& items, int q) {  // 找第一个大于q的位置
        int l = 0, r = items.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (items[mid][0] > q) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int cnt = 0;
        for (int i = 0; i < items.size(); i++) {
            cnt = items[i][1] = max(cnt, items[i][1]);
        }
        for (int i = 0; i < queries.size(); i++) {
            int index = getAns(items, queries[i]);
            queries[i] = index ? items[index - 1][1] : 0;
        }
        return queries;
    }
};