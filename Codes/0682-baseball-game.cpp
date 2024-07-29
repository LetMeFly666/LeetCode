/*
 * @Author: LetMeFly
 * @Date: 2024-07-29 22:40:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-29 22:43:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        for (string& op : operations) {
            if (op == "+") {
                score.push_back(score[score.size() - 1] + score[score.size() - 2]);
            }
            else if (op == "D") {
                score.push_back(score.back() * 2);
            }
            else if (op == "C") {
                score.pop_back();
            }
            else {
                score.push_back(atoi(op.c_str()));
            }
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};