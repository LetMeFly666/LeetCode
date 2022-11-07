/*
 * @Author: LetMeFly
 * @Date: 2022-11-07 10:19:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-07 10:32:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool aviliable(string& s) {  // 只接受至多一个.的s，只接受不为空的s
        if (s.size() > 1 && s[0] == '0' && s[1] != '.')  // 0axxx
            return false;
        if (s[0] == '.')  // .xx
            return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                if (s.back() == '0')  // x.x0
                    return false;
                if (i == s.size() - 1)
                    return false;
                break;
            }
        }
        return true;
    }

    vector<string> addPoint(string s) {
        vector<string> ans;
        if (aviliable(s))
            ans.push_back(s);
        for (int i = 0; i + 1 < s.size(); i++) {
            string thisS = s.substr(0, i + 1) + "." + s.substr(i + 1, s.size() - i - 1);
            if (aviliable(thisS))
                ans.push_back(thisS);
        }
        return ans;
    }
public:
    vector<string> ambiguousCoordinates(string& s) {
        s = s.substr(1, s.size() - 2);
        vector<string> ans;
        for (int i = 0; i + 1 < s.size(); i++) {
            vector<string> front = addPoint(s.substr(0, i + 1));
            vector<string> back = addPoint(s.substr(i + 1, s.size() - i - 1));
            for (string& s1 : front)
                for (string& s2 : back)
                    ans.push_back("(" + s1 + ", " + s2 + ")");
        }
        return ans;
    }
};

#ifdef _WIN32
/*
(123)

["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]

*/
/*
(00011)

["(0.001, 1)", "(0, 0.011)"]

*/
/*
(0123)

["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
*/
/*
(100)

[(10, 0)]

*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        debug(sol.ambiguousCoordinates(s));
    }
    return 0;
}
#endif