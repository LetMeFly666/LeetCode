/*
 * @Author: LetMeFly
 * @Date: 2023-03-22 10:07:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-22 11:01:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error
/*
错误的贪心算法：
贪心思路为：排序，年龄大的优先，相同年龄分数大的优先。
从前到后遍历队员，计算当前队员入队的话，队伍的总分（顶替掉与之不合之人），若分数更高则入队并替换，否则舍弃。

但是假设有这种情况：
排序后前两个人都为[5分, 2岁]，之后是100个[6分, 1岁]的人。
按照上述贪心算法，[6分, 1岁]之人无法顶替掉两个[5分, 2岁]之人（总分为10），所以[6分, 1岁]之人将被舍弃。
但实际上，100个[6分, 1岁]之人都入队的话，将能产生600分的贡献！
因此上述贪心思路错误。

替换操作前，不计算单人替换的得分情况，而是计算所有同分之人的分数和，来衡量十分替换，可以吗？
不可以。万一只有一个[6分, 1岁]之人，但有100个[6分, 0岁]之人呢？
*/
/*
错误的执行结果：

[6,5,1,7,6,5,5,4,10,4]
[3,2,5,3,2,1,4,4,5,1]

thisPeople: {10, 5} | Choosed: {10, 5},
thisPeople: {1, 5} | Choosed: {10, 5}, {1, 5},
thisPeople: {5, 4} | Choosed: {10, 5}, {5, 4},
thisPeople: {4, 4} | Choosed: {10, 5}, {5, 4}, {4, 4},
thisPeople: {7, 3} | Choosed: {10, 5}, {5, 4}, {4, 4},
thisPeople: {6, 3} | Choosed: {10, 5}, {5, 4}, {4, 4},
thisPeople: {6, 2} | Choosed: {10, 5}, {5, 4}, {4, 4},
thisPeople: {5, 2} | Choosed: {10, 5}, {5, 4}, {5, 2},
thisPeople: {5, 1} | Choosed: {10, 5}, {5, 4}, {5, 2}, {5, 1},
thisPeople: {4, 1} | Choosed: {10, 5}, {5, 4}, {5, 2}, {5, 1}, {4, 1},
29
*/
typedef pair<int, int> pii;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pii> a(scores.size());
        for (int i = 0; i < scores.size(); i++) {
            a[i] = {scores[i], ages[i]};
        }
        sort(a.begin(), a.end(), [](const pii& a, const pii& b) {
            return a.second != b.second ? a.second > b.second : a.first > b.first;  // 年龄大的优先，相同年龄分数大的优先
        });
        vector<pii> choosed;
        for (int i = 0; i < a.size(); i++) {
            int thisScore = a[i].first;
            int thisAge = a[i].second;
            int descScore = 0;
            for (int j = 0; j < choosed.size(); j++) {
                if (choosed[j].first < thisScore && choosed[j].second > thisAge) {
                    descScore += choosed[j].first;
                }
            }
            if (descScore <= thisScore) {  // 值得入队
                vector<pii> newChoosed;
                for (pii& p : choosed) {
                    if (!(p.first < thisScore && p.second > thisAge)) {
                        newChoosed.push_back(p);
                    }
                }
                newChoosed.push_back(a[i]);
                choosed = newChoosed;
            }
            cout << "thisPeople: {" << thisScore << ", " << thisAge << "} | Choosed: ";  for (pii& p : choosed) {cout << "{" << p.first << ", " << p.second << "}, ";} cout << endl;  //******
        }
        int ans = 0;
        for (pii& p : choosed) {
            ans += p.first;
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

    }
};
#endif  // FirstTry

#ifdef _WIN32
/*
[6,5,1,7,6,5,5,4,10,4]
[3,2,5,3,2,1,4,4,5,1]

43
*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        vector<int> va = stringToVector(a), vb = stringToVector(b);
        Solution sol;
        cout << sol.bestTeamScore(va, vb) << endl;
    }
    return 0;
}
#endif