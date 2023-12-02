/*
 * @Author: LetMeFly
 * @Date: 2023-12-02 12:27:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-02 14:13:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int nowPeopleCnt = 0;
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> nowPeople(cmp);
        for (vector<int>& trip : trips) {
            int num = trip[0], from = trip[1], to = trip[2];
            while (nowPeople.size() && nowPeople.top().second <= from) {
                nowPeopleCnt -= nowPeople.top().first;
                nowPeople.pop();
            }
            nowPeopleCnt += num;
            if (nowPeopleCnt > capacity) {
                return false;
            }
            nowPeople.push({num, to});
        }
        return true;
    }
};