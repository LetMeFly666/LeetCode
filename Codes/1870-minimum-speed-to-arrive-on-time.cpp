/*
 * @Author: LetMeFly
 * @Date: 2024-10-02 12:19:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-02 13:04:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
private:
    bool ok(vector<int>& dist, ll hour, int speed) {
        ll t = 0;
        for (int i = 0; i < dist.size() - 1; i++) {
            t += (dist[i] + speed - 1) / speed;
        }
        // if (speed == 5000001) {
        //     printf("debug\nt = %d, disk.back() = %d, speed = %d\nt * 100 + dist.back() * 100 / speed = %lld, hour = %lld\n", t, dist.back(), speed, t * 100 + dist.back() * 100 / speed, hour);
        // }
        return (hour - t * 100) * speed >= dist.back() * 100;
        // return t * 100 + dist.back() * 100 / speed <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        ll hour100 = llround(hour * 100);
        int l = 1, r = 1e7 + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (ok(dist, hour100, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l == 1e7 + 1 ? -1 : l;
    }
};

#ifdef _WIN32
int main() {
    vector<int> dist = {1, 1, 100000};
    double hour = 2.01;
    Solution sol;
    cout << sol.minSpeedOnTime(dist, hour) << endl;
    return 0;
}
#endif