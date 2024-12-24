/*
 * @Author: LetMeFly
 * @Date: 2024-12-24 10:56:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-24 18:41:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FristTry  // Half&WA - 不能只按照腐烂截止时间
// 例如不能为了吃截止时间为6的4,5而空出第3天
/*
[1,2,3,5,2]
[3,2,1,4,2]


<0-3, 1>, <1-3, 2>, <2-3, 1>, <3-7, 5>, <4-6, 2>
    0        1, 2                3, 6     4, 5
*/
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;  // [<rotDay, startDay, appleNum>, ...
        for (int i = 0; i < apples.size(); i++) {
            pq.push({days[i] + i, i, apples[i]});
        }
        int ans = 0, day = 0;
        while (pq.size()) {
            auto [rotDay, startDay, appleNum] = pq.top();
            pq.pop();
            int eat = max(0, min(appleNum, rotDay - max(startDay, day)));
            ans += eat;
            printf("day = %d, <rotDay, startDay, appleNum> = <%d, %d, %d>, eat = %d, dayNew = %d\n", day, rotDay, startDay, appleNum, eat, max(day, startDay - 1) + eat);  //************
            day = max(day, startDay) + eat;
        }
        return ans;
    }
};
#else  // FristTry
// SecondTry - 边遍历边入队
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int ans = 0, day = 0;
        for (; day < apples.size(); day++) {
            if (apples[day]) {
                pq.push({day + days[day], apples[day]});
            }
            while (pq.size()) {
                auto [rotDay, appleNum] = pq.top();
                pq.pop();
                if (rotDay <= day) {
                    continue;
                }
                ans++;
                appleNum--;
                if (appleNum) {
                    pq.push({rotDay, appleNum});
                }
                break;
            }
        }
        while (pq.size()) {
            auto [rotDay, appleNum] = pq.top();
            pq.pop();
            int eat = max(0, min(rotDay - day, appleNum));
            ans += eat;
            day += eat;
        }
        return ans;
    }
};
#endif  // FristTry

#ifdef _WIN32
/*
[1,2,3,5,2]
[3,2,1,4,2]

7
*/
int main() {
    string a, b;
    Solution sol;
    while (cin >> a >> b) {
        vector<int> va = stringToVector(a), vb = stringToVector(b);
        cout << sol.eatenApples(va, vb) << endl;
    }
    return 0;
}
#endif