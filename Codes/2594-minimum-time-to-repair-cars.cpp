/*
 * @Author: LetMeFly
 * @Date: 2023-09-07 14:47:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-07 15:22:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
private:
    bool check1(vector<int>& ranks, ll cars, ll t) {  // cars一定用ll，否则可能溢出！
        for (int r : ranks) {
            cars -= sqrt(t / r);
        }
        return cars <= 0;
    }

    bool check(vector<int>& ranks, ll cars, ll t) {
        ll cnt = 0;
        for (int r : ranks) {
            cnt += sqrt(t / r);
        }
        return cnt >= cars;
    };

public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1, r = 1e12;  // 完了，太长时间没打代码给1e12写成10^12了（6）
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(ranks, cars, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};

#ifdef _WIN32
/*
[4,2,3,1]
10

16
*/
int main() {
    string s;
    int t;
    while (cin >> s >> t) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.repairCars(v, t) << endl;
    }
    return 0;
}
#endif