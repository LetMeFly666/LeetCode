/*
 * @Author: LetMeFly
 * @Date: 2022-05-07 09:35:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-07 09:45:18
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const char aviliable[] = "ATCG";

class Solution {
private:
    set<string> se;
    set<string> ok;
public:
    int minMutation(string start, string end, vector<string>& bank) {
        for (string& s : bank)
            ok.insert(s);
        if (start == end)
            return 0;
        queue<pair<string, int>> q;
        q.push({start, 0});
        se.insert(start);
        while (q.size()) {
            auto [str, times] = q.front();
            if (str == end)
                return times;
            q.pop();
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 4; j++) {
                    if (str[i] != aviliable[j]) {
                        string newStr = str;
                        newStr[i] = aviliable[j];
                        if (ok.count(newStr) && !se.count(newStr)) {
                            q.push({newStr, times + 1});
                            se.insert(newStr);
                        }
                    }
                }
            }
        }
        return -1;
    }
};