/*
 * @Author: LetMeFly
 * @Date: 2023-03-22 10:07:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-22 10:44:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

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
            if (descScore < thisScore) {  // 值得入队
                vector<pii> newChoosed;
                for (pii& p : choosed) {
                    if (!(p.first < thisScore && p.second > thisAge)) {
                        newChoosed.push_back(p);
                    }
                }
                newChoosed.push_back(a[i]);
                choosed = newChoosed;
            }
            for (pii& p : choosed) {cout << "{" << p.first << ", " << p.second << "}, ";} cout << endl;  //******
        }
        int ans = 0;
        for (pii& p : choosed) {
            ans += p.first;
        }
        return ans;
    }
};

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