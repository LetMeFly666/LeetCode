/*
 * @Author: LetMeFly
 * @Date: 2022-11-01 20:27:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-01 20:58:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 字符串拼接
class Solution {
private:
    string concat(vector<string>& v) {
        string ans;
        for (auto& s : v) {
            ans += s;
        }
        return ans;
    }
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return concat(word1) == concat(word2);
    }
};
#else  // FirstTry
// SecondTry  // 通过指针比较
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int locWords1 = 0, locWord1 = 0;
        int locWords2 = 0, locWord2 = 0;
        bool end1 = false, end2 = false;
        while (true) {
            if (word1[locWords1][locWord1] != word2[locWords2][locWord2]) {
                return false;
            }
            locWord1++, locWord2++;
            if (locWord1 == word1[locWords1].size()) {
                locWord1 = 0, locWords1++;
                if (locWords1 == word1.size())
                    end1 = true;
            }
            if (locWord2 == word2[locWords2].size()) {
                locWord2 = 0, locWords2++;
                if (locWords2 == word2.size())
                    end2 = true;
            }
            if (end1 != end2)
                return false;
            if (end1)
                return true;
        }
    }
};
#endif  // FirstTry