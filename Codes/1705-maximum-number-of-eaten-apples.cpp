/*
 * @Author: LetMeFly
 * @Date: 2021-12-24 07:33:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-24 08:56:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


#ifdef False0
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        vector<int> dies(20000 + apples.size());
        // dbg(dies.size()); //**********
        int sum = 0;
        int ans = 0;
        int lastDay = apples.size();
        int firstDie = 0;
        for (int i = 0; i < lastDay; i++) {
            sum -= dies[i];
            firstDie = max(firstDie, i + 1);
            if (i < apples.size()) {
                sum += apples[i];
                // dbg(i + days[i]); //******
                dies[i + days[i]] += apples[i];
                lastDay = max(lastDay, i + days[i]);
                firstDie = min(firstDie, lastDay);
            }
            if (sum) {
                ans++;
                sum--;
                while (!dies[firstDie]) {
                    firstDie++;
                }
                dies[firstDie]--;
            }
            // printf("i = %d, ")
        }
        // int i = apples.size();
        // while (sum) {
        //     sum -= dies[i];
        // }
        return ans;
    }
};
#else
/*
[1,2,3,5,2]
[3,2,1,4,2]

*/

/*
[2,1,1,4,5]
[10,10,6,4,2]

*/

/*
[1]
[2]

*/
typedef pair<int, int> pii;
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pii, vector<pii>, greater<pii>> q;
        int ans = 0;
        // int sum = 0;
        int lastDay = apples.size();
        for (int i = 0; i < lastDay; i++) {
            if (i < apples.size() && apples[i] > 0) 
                q.emplace(i + days[i], apples[i]),
                lastDay = max(lastDay, i + days[i]);
            while (q.size() && q.top().first <= i)
                q.pop();
            if (q.empty())
                continue;
            auto[day, num] = q.top();
            q.pop();
            num--, ans++;
            if (num)
                q.emplace(day, num);
        }
        return ans;
    }
};
#endif

#ifdef _WIN32
int main() {
    string a, b;
    while (cin >> a >> b) {
        Solution sol;
        vector<int>va = stringToVector(a), vb = stringToVector(b);
        cout << sol.eatenApples(va, vb) << endl;
    }
    return 0;
}
#endif