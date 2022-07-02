/*
 * @Author: LetMeFly
 * @Date: 2022-07-02 17:19:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-02 17:32:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(), stations.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        int ans = 0;
        int canGo = startFuel;
        int loc = 0;
        priority_queue<int> pq;
        while (canGo < target) {
            while (loc < stations.size() && stations[loc][0] <= canGo) {
                pq.push(stations[loc][1]);
                loc++;
            }
            if (pq.empty())
                return -1;
            canGo += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};