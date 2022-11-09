/*
 * @Author: LetMeFly
 * @Date: 2022-04-11 09:13:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-11 10:14:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // [2022-04-11 09:13:54, 2022-04-11 09:16:37]
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (diff.size() == 2)
                    return false;
                diff.push_back(i);
            }
        }
        if (diff.size() == 1)
            return false;
        if (diff.size() == 0)
            return true;
        if (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]) {
            return true;
        }
        return false;
    }
};
#else  // FirstTry
#ifdef SecondTry  // 2022-10-11 二刷
class Solution {
public:
    bool areAlmostEqual(string& s1, string& s2) {
        if (s1.size() != s2.size())
            return false;
        int firstDiffLoc = -1, secondDiffLoc = -1;
        for (int i = s1.size() - 1; i >= 0; i--) {
            if (s1[i] != s2[i]) {
                if (firstDiffLoc == -1) {
                    firstDiffLoc = i;
                }
                else if (secondDiffLoc == -1) {
                    secondDiffLoc = i;
                }
                else {
                    return false;
                }
            }
        }
        if (firstDiffLoc == -1)  // 全相同
            return true;
        if (secondDiffLoc != -1 && (s1[firstDiffLoc] == s2[secondDiffLoc] && s1[secondDiffLoc] == s2[firstDiffLoc]))  // 正好两个不同，且不同的那两个互换后相同了
            return true;
        return false;
    }
};
#else  // SecondTry
// ThirdTry  // 2022-10-11 二刷 方法二：竞赛时法
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        vector<int> diff;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }
        if (diff.empty())
            return true;
        if (diff.size() == 2 && (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]))
            return true;
        return false;
    }
};
#endif  // SecondTry
#endif  // FirstTry