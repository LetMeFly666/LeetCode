/*
 * @Author: LetMeFly
 * @Date: 2025-12-27 23:12:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-27 23:27:22
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// THIS CANNOT ACCESS
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<>> canuse;
        for (int i = 0; i < n; i++) {
            canuse.push(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> inuse;
        vector<int> times(n);
        for (vector<int>& meeting : meetings) {
            // 先看有没有新释放的
            while (!inuse.empty() && inuse.top().first <= meeting[0]) {
                auto[_, thisRoom] = inuse.top();
                canuse.push(thisRoom);
                inuse.pop();
            }
            int thisRoom, endTime;
            // 看看有没有空的
            if (!canuse.empty()) {
                thisRoom = canuse.top();
                endTime = meeting[1];
            } else {  // 等到第一个释放
                auto[freeTime, room] = inuse.top();
                endTime = freeTime + meeting[1] - meeting[0];
                inuse.pop();
            }
            canuse.pop();
            times[thisRoom]++;
            inuse.push({endTime, thisRoom});
        }
        return max_element(times.begin(), times.end()) - times.begin();
    }
};