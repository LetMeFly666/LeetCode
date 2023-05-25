#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words[0].size();
        for (int j = 0; j < n - 1; j++) {
            unordered_map<int, int> ma;
            for (int i = 0; i < words.size(); i++) {
                ma[words[i][j + 1] - words[i][j]]++;
            }
            for (int i = 0; i < words.size(); i++) {
                if (ma[words[i][j + 1] - words[i][j]] == 1) {
                    return words[i];
                }
            }
        }
        return "";  // FAKE RETURN
    }
};

// class Solution {
// public:
//     string oddString(vector<string>& words) {
//         int n = words[0].size();
//         for (int j = 0; j < n - 1; j++) {
//             int ma[2], val[2], loc = 0;
//             for (int i = 0; i < words.size(); i++) {
//                 int thisDiff = words[i][j + 1] - words[i][j];
//                 bool found = false;
//             }
//         }
//     }
// };