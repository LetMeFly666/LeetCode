/*
 * @Author: LetMeFly
 * @Date: 2023-10-11 09:40:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-11 09:50:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> postive, negative;
        for (string& s : positive_feedback) {
            postive.insert(s);
        }
        for (string& s : negative_feedback) {
            negative.insert(s);
        }
        vector<pair<int, int>> v;
        for (int i = 0; i < report.size(); i++) {
            int lastSpace = -1;
            int thisScore = 0;
            for (int j = 0; j <= report[i].size(); j++) {
                if (j == report[i].size() || report[i][j] == ' ') {  // (lastSpace, j)
                    string thisWord = report[i].substr(lastSpace + 1, j - lastSpace - 1);
                    lastSpace = j;
                    if (postive.count(thisWord)) {
                        thisScore += 3;
                    }
                    else if (negative.count(thisWord)) {
                        thisScore -= 1;
                    }
                }
            }
            v.push_back({-thisScore, student_id[i]});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};