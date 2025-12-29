#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    unordered_map<int, vector<char>> can;

    inline int bottom2int(char a, char b) {
        return (a - '0') * 26 + b;
    }

    bool dfs(string bottom) {
        if (bottom.size() == 1) {
            return true;
        }
        
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string& s : allowed) {
            can[bottom2int(s[0], s[1])].push_back(s[2]);
        }
        return dfs(bottom);
    }
};