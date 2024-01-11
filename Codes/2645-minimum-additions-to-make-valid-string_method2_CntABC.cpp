#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int addMinimum(string word) {
        int cntABC = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] <= word[i - 1]) {
                cntABC++;
            }
        }
        return cntABC * 3 - word.size();
    }
};