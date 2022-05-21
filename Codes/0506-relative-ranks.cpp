/*
 * @Author: LetMeFly
 * @Date: 2021-12-02 14:35:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-02 14:41:53
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

typedef struct {
    int originalTh;
    int score;
    int th;
} pii;
bool cmpByScore(const pii & a, const pii & b) {
    return a.score > b.score;
}
bool cmpByOriginalTh(const pii & a, const pii & b) {
    return a.originalTh < b.originalTh;
}
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pii> a(score.size());
        for (int i = 0; i < score.size(); i++) {
            a[i].originalTh = i;
            a[i].score = score[i];
        }
        sort(a.begin(), a.end(), cmpByScore);
        for (int i = 0; i < a.size(); i++) {
            a[i].th = i + 1;
        }
        sort(a.begin(), a.end(), cmpByOriginalTh);
        vector<string> ans;
        for (pii &thisPiar : a) {
            switch (thisPiar.th) {
                case 1: ans.push_back("Gold Medal"); break;
                case 2: ans.push_back("Silver Medal"); break;
                case 3: ans.push_back("Bronze Medal"); break;
                default : ans.push_back(to_string(thisPiar.th));
            }
        }
        return ans;
    }
};