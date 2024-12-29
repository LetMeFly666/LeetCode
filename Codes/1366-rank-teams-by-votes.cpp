/*
 * @Author: LetMeFly
 * @Date: 2024-12-29 14:17:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-29 14:24:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int voter = votes.size(), voted = votes[0].size();
        vector<vector<int>> counts(26, vector<int>(voted));
        for (string& vote : votes) {
            for (int i = 0; i < voted; i++) {
                counts[vote[i] - 'A'][i]++;
            }
        }
        string ans = votes[0];
        sort(ans.begin(), ans.end(), [&](const char& a, const char& b) {
            vector<int>& va = counts[a - 'A'], &vb = counts[b - 'A'];
            for (int i = 0; i < voted; i++) {
                if (va[i] != vb[i]) {
                    return va[i] > vb[i];
                }
            }
            return a < b;
        });
        return ans;
    }
};