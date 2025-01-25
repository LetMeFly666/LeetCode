/*
 * @Author: LetMeFly
 * @Date: 2025-01-25 08:08:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-25 09:53:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
先选赔的
    [[6, 4], [3, 2]]：
        先[6, 4]的话需要初始资金max(6, 6+3-4)=max(6, 5)=6=max(6, (6-4)+(3-2)+2)
        先[3, 2]的话需要初始资金max(3, 6+3-2)=max(3, 7)=7=(3-2)+(6-4)+4
    对于赔的：
        初始资金：赔钱总额+最大cashback
        结束资金：最大cashback
后选不赔的
    赚的一样：[[1, 2], [2, 3]]，先[2, 3]再[1, 2]
    赚的不同：
        [[3, 5], [7, 8]]：
            先[3, 5]的话需要初始资金7-(5-3)=5
            先[7, 8]的话需要初始资金7
    反正就是只要钱到了最大的“cost”，钱就够了。
    如果先投资“cost”比较小的话，一定会赚，本金加上赚的钱达到最大cost就行，所以初始值所需较小。
*/
typedef long long ll;

class Solution {
public:
    ll minimumMoney(vector<vector<int>>& transactions) {
        ll ans = 0;
        int M_pei = 0;
        // 先算赔的
        for (vector<int>& transaction : transactions) {
            if (transaction[1] < transaction[0]) {
                ans += transaction[0] - transaction[1];
                M_pei = max(M_pei, transaction[1]);
            }
        }
        ans += M_pei;
        // 再算赚的，初始资金M_pei
        int M_zhuan = 0;
        for (vector<int>& transaction : transactions) {
            if (transaction[1] >= transaction[0]) {
                M_zhuan = max(M_zhuan, transaction[0]);
            }
        }
        ans += max(M_zhuan - M_pei, 0);
        return ans;
    }
};

#ifdef _WIN32
/*
[[2,1],[5,0],[4,2]]

10
*/
/*
[[36,79],[94,94],[12,54],[71,25],[34,78],[89,66],[66,25],[7,29],[5,58],[2,25],[10,83],[62,62],[11,52],[40,5],[10,79],[74,53],[33,90],[91,81],[30,84]]

270
*/

// 暴力验证一个答案是否正确，复杂度O(len(t)!)，对于10以内的数据还算可行
bool isok_baoliYanzheng(vector<vector<int>>& t, ll init) {
    sort(t.begin(), t.end());
    auto isok = [](vector<vector<int>>& t, ll init) {
        for (vector<int>& t0 : t) {
            if (init < t0[0]) {
                return false;
            }
            init += t0[1] - t0[0];
        }
        return true;
    };
    do {
        for (vector<int>& t0 : t) {
            cout << '(' << t0[0] << ", " << t0[1] << "), ";
        }
        cout << endl;
        bool isThisOk = isok(t, init);
        if (!isThisOk) {
            return false;
        }
    } while (next_permutation(t.begin(), t.end()));
    return true;
}

int main() {
    string s;
    Solution sol;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        debug(v);
        ll ans = sol.minimumMoney(v);
        dbg(ans);
        if (v.size() <= 10) {
            cout << "ifOk: ";
            fflush(stdout);
            cout << isok_baoliYanzheng(v, ans) << endl;
        }
    }
    return 0;
}
#endif