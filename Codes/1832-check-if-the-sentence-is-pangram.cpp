/*
 * @Author: LetMeFly
 * @Date: 2022-12-13 16:29:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-13 16:30:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkIfPangram(string& sentence) {
        bool visited[26] = {false};
        for (char c : sentence)
            visited[c - 'a'] = true;
        for (int i = 0; i < 26; i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
};