/*
 * @Author: LetMeFly
 * @Date: 2022-08-19 08:54:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-19 09:00:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error，必须是双射（一一映射），不能多对一
class Solution {
public:
    bool isIsomorphic(string& s, string& t) {
        int mapper[26] = {0};
        for (int i = s.size() - 1; i >= 0; i--) {
            if (mapper[s[i] - 'a'] && mapper[s[i] - 'a'] - 1 != t[i] - 'a')
                return false;
            mapper[s[i] - 'a'] = t[i] - 'a' + 1;
        }
        return true;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    bool isIsomorphic(string& s, string& t) {
        unordered_map<char, char> ma;
        unordered_set<char> se;
        for (int i = t.size() - 1; i >= 0; i--) {
            if (ma.count(s[i])) {
                if (ma[s[i]] != t[i])
                    return false;
            }
            else {
                if (se.count(t[i]))
                    return false;
                se.insert(t[i]);
                ma[s[i]] = t[i];
            }
        }
        return true;
    }
};
#endif  // FirstTry