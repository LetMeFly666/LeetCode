/*
 * @Author: LetMeFly
 * @Date: 2025-03-08 17:34:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-08 21:15:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// WA!!!! ....... 难顶
typedef long long ll;
class Solution {
public:
    ll maximumBeauty(vector<int>& flowers, ll newFlowers, int target, ll full, ll partial) {
        sort(flowers.begin(), flowers.end());
        ll need = 0;
        int canFullFrom = flowers.size();
        for (int i = flowers.size() - 1; i >= 0; i--) {
            int thisNeed = max(0, target - flowers[i]);
            need += thisNeed;
            if (need > newFlowers) {
                break;
            }
            newFlowers -= thisNeed;
            canFullFrom = i;
        }
        if (!need) {  // 不需额外，本就全full，莫得选择
            return full * flowers.size();
        }
        if (!canFullFrom) {  // 可以从0开始全full，花量充足
            return max(flowers.size() * full, (flowers.size() - 1) * full + (target - 1) * partial);
        }
        ll ans = 0;
        int left = 0, fullTo = flowers[0];  // [0, ..., left]都填满了fullTo朵花
        for (; canFullFrom < flowers.size(); canFullFrom++) {
            while (left + 1 < canFullFrom && newFlowers >= (left + 1) * (flowers[left + 1] - fullTo)) {
                newFlowers -= (left + 1) * (flowers[left + 1] - fullTo);
                left++;
                fullTo = flowers[left];
            }
            int stillFull = min(newFlowers / canFullFrom, (ll)target - fullTo - 1);
            fullTo += stillFull;
            newFlowers -= stillFull * canFullFrom;
            ans = max(ans, (ll)(fullTo * partial + (flowers.size() - canFullFrom) * full));  // 力扣上这个为啥是max(ll, ull)啊
            if (flowers[canFullFrom] >= target) {
                break;
            }
            newFlowers += target - flowers[canFullFrom];
        }
        return ans;
    }
};

#ifdef _WIN32
/*
[5,19,1,1,6,10,18,12,20,10,11]
6
20
3
11

47
*/
/*
[1,1]
2
2
1
2

3
*/
/*
[1,3,1,1]
7
6
12
1

14
*/
/*
[1,98]
5
99
12
1

17
*/
int main() {
    string s;
    int a, b, c, d;
    while (cin >> s >> a >> b >> c >> d) {
        Solution sol;
        vector<int> v = stringToVector(s);
        cout << sol.maximumBeauty(v, a, b, c, d) << endl;
    }
    return 0;
}
#endif